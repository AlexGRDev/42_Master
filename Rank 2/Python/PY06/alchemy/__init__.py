# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    __init__.py                                       :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 19:01:05 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/15 19:01:39 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from alchemy.elements import create_air

__all__: list[str] = ["create_air"]


def heal() -> str:
    from alchemy.potions import healing_potion
    return healing_potion()
