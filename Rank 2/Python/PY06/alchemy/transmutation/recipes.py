# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    recipes.py                                        :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:03:52 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:04:35 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from alchemy.elements import create_air, create_fire
from alchemy.potions import strength_potion


def lead_to_gold() -> str:
    air = create_air()
    strength = strength_potion()
    fire = create_fire()
    return (f"Recipe transmuting Lead to Gold: brew '{air}' and "
            f"'{strength}' mixed with '{fire}'")
