# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    factories.py                                      :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:09:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:25:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex0 import CreatureFactory
from ex1.heal_creatures import Bloomelle, Sproutling
from ex1.transform_creatures import Morphagon, Shiftling


class HealingCreatureFactory(CreatureFactory):

    def create_base(self) -> Sproutling:
        return Sproutling()

    def create_evolved(self) -> Bloomelle:
        return Bloomelle()


class TransformCreatureFactory(CreatureFactory):

    def create_base(self) -> Shiftling:
        return Shiftling()

    def create_evolved(self) -> Morphagon:
        return Morphagon()
