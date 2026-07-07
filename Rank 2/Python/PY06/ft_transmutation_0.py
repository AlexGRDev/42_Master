# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_transmutation_0.py                             :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:15:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:16:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import alchemy.transmutation.recipes

print("=== Transmutation 0 ===")
print("Using file alchemy/transmutation/recipes.py directly")
result = alchemy.transmutation.recipes.lead_to_gold()
print(f"Testing lead to gold: {result}")
