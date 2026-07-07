# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_alembic_2.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:03:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:04:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import alchemy.elements

print("=== Alembic 2 ===")
print("Accessing alchemy/elements.py using 'import ...' structure")
result = alchemy.elements.create_earth()
print(f"Testing create_earth: {result}")
