# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    heal_creatures.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:07:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:07:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex0 import Creature
from ex1.heal import HealCapability


class Sproutling(Creature, HealCapability):

    def __init__(self) -> None:
        Creature.__init__(self, "Sproutling", "Grass")

    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"

    def heal(self, target: str = "itself") -> str:
        return "Sproutling heals itself for a small amount"


class Bloomelle(Creature, HealCapability):

    def __init__(self) -> None:
        Creature.__init__(self, "Bloomelle", "Grass/Fairy")

    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"

    def heal(self, target: str = "itself") -> str:
        return "Bloomelle heals itself and others for a large amount"
