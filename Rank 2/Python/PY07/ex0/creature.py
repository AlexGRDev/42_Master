# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    creature.py                                       :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:00:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:00:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod


class Creature(ABC):

    def __init__(self, name: str, type_: str) -> None:
        self.name = name
        self.type = type_

    @abstractmethod
    def attack(self) -> str:
        ...

    def describe(self) -> str:
        return f"{self.name} is a {self.type} type Creature"
