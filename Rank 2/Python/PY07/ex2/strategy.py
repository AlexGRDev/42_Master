# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    strategy.py                                       :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:12:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:12:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod

from ex0 import Creature


class BattleStrategy(ABC):

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        ...

    @abstractmethod
    def act(self, creature: Creature) -> list[str]:
        ...
