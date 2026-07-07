# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    factory.py                                        :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:02:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:02:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod

from ex0.creature import Creature


class CreatureFactory(ABC):

    @abstractmethod
    def create_base(self) -> Creature:
        ...

    @abstractmethod
    def create_evolved(self) -> Creature:
        ...
