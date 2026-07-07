# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    functools_artifacts.py                            :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 17:06:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 17:07:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


import functools
import operator
from collections.abc import Callable
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    if operation == "add":
        return functools.reduce(operator.add, spells)
    if operation == "multiply":
        return functools.reduce(operator.mul, spells)
    if operation == "max":
        return functools.reduce(lambda a, b: a if a > b else b, spells)
    if operation == "min":
        return functools.reduce(lambda a, b: a if a < b else b, spells)
    raise ValueError(f"Unknown operation: {operation}")


def partial_enchanter(
    base_enchantment: Callable[[int, str, str], str],
) -> dict[str, Callable[[str], str]]:
    return {
        "fire": functools.partial(base_enchantment, 50, "fire"),
        "ice": functools.partial(base_enchantment, 50, "ice"),
        "lightning": functools.partial(base_enchantment, 50, "lightning"),
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def dispatch(spell: object) -> str:
        return "Unknown spell type"

    @dispatch.register
    def _(spell: int) -> str:
        return f"Damage spell: {spell} damage"

    @dispatch.register
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @dispatch.register(list)
    def _(spell: list[object]) -> str:
        return f"Multi-cast: {len(spell)} spells"

    return dispatch


if __name__ == "__main__":
    print("Testing spell reducer...")
    spells = [10, 20, 30, 40]
    print(f"Sum: {spell_reducer(spells, 'add')}")
    print(f"Product: {spell_reducer(spells, 'multiply')}")
    print(f"Max: {spell_reducer(spells, 'max')}")
    print(f"Min: {spell_reducer(spells, 'min')}")
    print(f"Empty list: {spell_reducer([], 'add')}")
    try:
        spell_reducer(spells, "unknown")
    except ValueError as error:
        print(f"Error caught: {error}")

    print("\nTesting partial enchanter...")

    def enchant_item(power: int, element: str, target: str) -> str:
        return f"{target} enchanted with {element} at power {power}"

    enchantments = partial_enchanter(enchant_item)
    print(enchantments["fire"]("Sword"))
    print(enchantments["ice"]("Shield"))
    print(enchantments["lightning"]("Bow"))

    print("\nTesting memoized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print(f"Cache info: {memoized_fibonacci.cache_info()}")

    print("\nTesting spell dispatcher...")
    dispatcher = spell_dispatcher()
    print(dispatcher(42))
    print(dispatcher("fireball"))
    print(dispatcher([1, 2, 3]))
    print(dispatcher(3.14))
