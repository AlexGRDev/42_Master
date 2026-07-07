# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    heal.py                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:05:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:05:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod


class HealCapability(ABC):

    @abstractmethod
    def heal(self, target: str = "itself") -> str:
        ...
