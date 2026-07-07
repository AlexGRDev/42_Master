# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    tournament.py                                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:17:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:17:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex0 import AquaFactory, CreatureFactory, FlameFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    BattleStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
    NormalStrategy,
)

Opponent = tuple[CreatureFactory, BattleStrategy]


def fight(opponent_a: Opponent, opponent_b: Opponent) -> None:
    factory_a, strategy_a = opponent_a
    factory_b, strategy_b = opponent_b
    creature_a = factory_a.create_base()
    creature_b = factory_b.create_base()

    print("* Battle *")
    print(creature_a.describe())
    print(" vs.")
    print(creature_b.describe())
    print(" now fight!")
    for line in strategy_a.act(creature_a):
        print(line)
    for line in strategy_b.act(creature_b):
        print(line)


def battle(opponents: list[Opponent]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print()
    for i in range(len(opponents)):
        for j in range(i + 1, len(opponents)):
            fight(opponents[i], opponents[j])


if __name__ == "__main__":
    flame = FlameFactory()
    aqua = AquaFactory()
    healing = HealingCreatureFactory()
    transforming = TransformCreatureFactory()

    normal = NormalStrategy()
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()

    scenarios: list[tuple[str, str, list[Opponent]]] = [
        (
            "Tournament 0 (basic)",
            " [ (Flameling+Normal), (Healing+Defensive) ]",
            [(flame, normal), (healing, defensive)],
        ),
        (
            "Tournament 1 (error)",
            " [ (Flameling+Aggressive), (Healing+Defensive) ]",
            [(flame, aggressive), (healing, defensive)],
        ),
        (
            "Tournament 2 (three-way)",
            " [ (Flameling+Normal), (Healing+Defensive), "
            "(Transforming+Aggressive) ]",
            [
                (flame, normal),
                (healing, defensive),
                (transforming, aggressive),
            ],
        ),
        (
            "Tournament 3 (mixed factories)",
            " [ (Aqua+Normal), (Healing+Defensive), "
            "(Transforming+Aggressive) ]",
            [
                (aqua, normal),
                (healing, defensive),
                (transforming, aggressive),
            ],
        ),
    ]

    for title, description, opponents in scenarios:
        print(title)
        print(description)
        try:
            battle(opponents)
        except InvalidStrategyError as error:
            print(f"Battle error, aborting tournament: {error}")
        print()
