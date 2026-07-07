# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_alembic_1.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:01:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:02:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from elements import create_water

print("=== Alembic 1 ===")
print("Using: 'from ... import ...' structure to access elements.py")
result = create_water()
print(f"Testing create_water: {result}")
