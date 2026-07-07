# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_distillation_0.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:11:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:12:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from alchemy.potions import healing_potion, strength_potion

print("=== Distillation 0 ===")
print("Direct access to alchemy/potions.py")
result = strength_potion()
print(f"Testing strength_potion: {result}")
result = healing_potion()
print(f"Testing healing_potion: {result}")
