# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    transform.py                                      :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:06:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:06:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from abc import ABC, abstractmethod


class TransformCapability(ABC):

    def __init__(self) -> None:
        self._transformed: bool = False

    @abstractmethod
    def transform(self) -> str:
        ...

    @abstractmethod
    def revert(self) -> str:
        ...
