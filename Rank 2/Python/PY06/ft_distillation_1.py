# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_distillation_1.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:13:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:14:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import alchemy

print("=== Distillation 1 ===")
print("Using: 'import alchemy' structure to access potions")
result = alchemy.strength_potion()
print(f"Testing strength_potion: {result}")
result = alchemy.heal()
print(f"Testing heal alias: {result}")
