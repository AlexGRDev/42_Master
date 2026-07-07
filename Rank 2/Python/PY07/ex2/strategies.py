# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    strategies.py                                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 09:13:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 09:13:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from ex0 import Creature
from ex1 import HealCapability, TransformCapability
from ex2.exceptions import InvalidStrategyError
from ex2.strategy import BattleStrategy


class NormalStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> list[str]:
        if not self.is_valid(creature):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' for this "
                "normal strategy"
            )
        return [creature.attack()]


class AggressiveStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> list[str]:
        if not isinstance(creature, TransformCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' for this "
                "aggressive strategy"
            )
        return [
            creature.transform(),
            creature.attack(),
            creature.revert(),
        ]


class DefensiveStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> list[str]:
        if not isinstance(creature, HealCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' for this "
                "defensive strategy"
            )
        return [creature.attack(), creature.heal()]
