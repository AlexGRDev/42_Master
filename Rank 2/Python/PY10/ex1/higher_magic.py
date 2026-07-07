# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    higher_magic.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 17:02:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 17:03:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from collections.abc import Callable

Spell = Callable[[str, int], str]
CombinedSpell = Callable[[str, int], tuple[str, str]]
Condition = Callable[[str, int], bool]
Sequence = Callable[[str, int], list[str]]


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    return f"Heals {target} for {power} HP"


def frostbolt(target: str, power: int) -> str:
    return f"Frostbolt chills {target} for {power} damage"


def spell_combiner(spell1: Spell, spell2: Spell) -> CombinedSpell:
    def combined(target: str, power: int) -> tuple[str, str]:
        return (spell1(target, power), spell2(target, power))
    return combined


def power_amplifier(base_spell: Spell, multiplier: int) -> Spell:
    def amplified(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplified


def conditional_caster(condition: Condition, spell: Spell) -> Spell:
    def caster(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return caster


def spell_sequence(spells: list[Spell]) -> Sequence:
    def sequence(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]
    return sequence


if __name__ == "__main__":
    print("Testing spell combiner...")
    combo = spell_combiner(fireball, heal)
    fire_result, heal_result = combo("Dragon", 20)
    print(f"Combined spell result: {fire_result}, {heal_result}")

    print("\nTesting power amplifier...")
    amplified_fireball = power_amplifier(fireball, 3)
    print(f"Original: {10}, Amplified: {10 * 3}")
    print(fireball("Goblin", 10))
    print(amplified_fireball("Goblin", 10))

    print("\nTesting conditional caster...")

    def has_enough_power(target: str, power: int) -> bool:
        return power >= 15

    safe_fireball = conditional_caster(has_enough_power, fireball)
    print(safe_fireball("Orc", 20))
    print(safe_fireball("Orc", 5))

    print("\nTesting spell sequence...")
    combo_sequence = spell_sequence([fireball, heal, frostbolt])
    for line in combo_sequence("Titan", 12):
        print(line)
