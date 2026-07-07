# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    capacitor.py                                      :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:16:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:16:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex1 import HealingCreatureFactory, TransformCreatureFactory


def test_healing(factory: HealingCreatureFactory) -> None:
    print("Testing Creature with healing capability")
    base = factory.create_base()
    print(" base:")
    print(base.describe())
    print(base.attack())
    print(base.heal())

    evolved = factory.create_evolved()
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.heal())


def test_transform(factory: TransformCreatureFactory) -> None:
    print("Testing Creature with transform capability")
    base = factory.create_base()
    print(" base:")
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())

    evolved = factory.create_evolved()
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())


if __name__ == "__main__":
    test_healing(HealingCreatureFactory())
    print()
    test_transform(TransformCreatureFactory())
