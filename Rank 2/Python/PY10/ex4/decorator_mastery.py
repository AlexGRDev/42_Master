# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    decorator_mastery.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 17:08:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 17:09:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


import functools
import time
from collections.abc import Callable
from typing import Concatenate, ParamSpec, TypeVar, cast

P = ParamSpec("P")
R = TypeVar("R")


def spell_timer(func: Callable[P, R]) -> Callable[P, R]:
    @functools.wraps(func)
    def wrapper(*args: P.args, **kwargs: P.kwargs) -> R:
        print(f"Casting {func.__name__}...")
        start = time.perf_counter()
        result = func(*args, **kwargs)
        elapsed = time.perf_counter() - start
        print(f"Spell completed in {elapsed:.3f} seconds")
        return result
    return wrapper


def power_validator(
    min_power: int,
) -> Callable[
    [Callable[Concatenate[int, P], str]],
    Callable[Concatenate[int, P], str],
]:
    def decorator(
        func: Callable[Concatenate[int, P], str],
    ) -> Callable[Concatenate[int, P], str]:
        @functools.wraps(func)
        def wrapper(power: int, *args: P.args, **kwargs: P.kwargs) -> str:
            if power >= min_power:
                return func(power, *args, **kwargs)
            return "Insufficient power for this spell"
        return cast(Callable[Concatenate[int, P], str], wrapper)
    return decorator


def retry_spell(
    max_attempts: int,
) -> Callable[[Callable[P, R]], Callable[P, R | str]]:
    def decorator(func: Callable[P, R]) -> Callable[P, R | str]:
        @functools.wraps(func)
        def wrapper(*args: P.args, **kwargs: P.kwargs) -> R | str:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(
                            f"Spell failed, retrying... "
                            f"(attempt {attempt}/{max_attempts})"
                        )
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


@power_validator(10)
def _cast_spell(power: int, spell_name: str) -> str:
    return f"Successfully cast {spell_name} with {power} power"


class MageGuild:

    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) >= 3 and all(
            ch.isalpha() or ch == " " for ch in name
        )

    def cast_spell(self, spell_name: str, power: int) -> str:
        return _cast_spell(power, spell_name)


@spell_timer
def fireball(target: str) -> str:
    time.sleep(0.05)
    return f"Fireball cast on {target}!"


@retry_spell(3)
def always_fails(target: str) -> str:
    raise RuntimeError(f"Spell backfired on {target}")


def make_flaky_spell() -> Callable[[str], str]:
    attempts_left = [2]

    def flaky(target: str) -> str:
        attempts_left[0] -= 1
        if attempts_left[0] > 0:
            raise RuntimeError("Unstable mana flow")
        return f"Spell finally landed on {target}!"
    return flaky


if __name__ == "__main__":
    print("Testing spell timer...")
    print(f"Result: {fireball('Dragon')}")

    print("\nTesting retrying spell (always fails)...")
    print(always_fails("Golem"))

    print("\nTesting retrying spell (succeeds partway)...")
    flaky_spell = retry_spell(3)(make_flaky_spell())
    print(flaky_spell("Wraith"))

    print("\nTesting MageGuild...")
    print(MageGuild.validate_mage_name("Gandalf"))
    print(MageGuild.validate_mage_name("G4ndalf!"))
    guild = MageGuild()
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Lightning", 5))
