# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    potions.py                                        :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:02:16 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:02:50 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from alchemy.elements import create_air, create_earth


def healing_potion() -> str:
    earth = create_earth()
    air = create_air()
    return f"Healing potion brewed with '{earth}' and '{air}'"


def strength_potion() -> str:
    from elements import create_fire, create_water
    fire = create_fire()
    water = create_water()
    return f"Strength potion brewed with '{fire}' and '{water}'"
