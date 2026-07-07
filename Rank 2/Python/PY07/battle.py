# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    battle.py                                         :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:15:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:15:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex0 import AquaFactory, CreatureFactory, FlameFactory


def test_factory(factory: CreatureFactory) -> None:
    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())


def battle(
    factory_a: CreatureFactory,
    factory_b: CreatureFactory,
) -> None:
    print("Testing battle")
    fighter_a = factory_a.create_base()
    fighter_b = factory_b.create_base()
    print(fighter_a.describe())
    print(" vs.")
    print(fighter_b.describe())
    print(" fight!")
    print(fighter_a.attack())
    print(fighter_b.attack())


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()

    test_factory(flame_factory)
    print()
    test_factory(aqua_factory)
    print()
    battle(flame_factory, aqua_factory)
