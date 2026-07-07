# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    factories.py                                      :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:03:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:03:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex0.creature import Creature
from ex0.creatures import Aquabub, Flameling, Pyrodon, Torragon
from ex0.factory import CreatureFactory


class FlameFactory(CreatureFactory):

    def create_base(self) -> Creature:
        return Flameling()

    def create_evolved(self) -> Creature:
        return Pyrodon()


class AquaFactory(CreatureFactory):

    def create_base(self) -> Creature:
        return Aquabub()

    def create_evolved(self) -> Creature:
        return Torragon()
