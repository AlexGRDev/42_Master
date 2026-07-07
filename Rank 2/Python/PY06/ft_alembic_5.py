# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_alembic_5.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:09:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:10:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from alchemy import create_air

print("=== Alembic 5 ===")
print("Accessing the alchemy module using 'from alchemy import ...'")
result = create_air()
print(f"Testing create_air: {result}")
