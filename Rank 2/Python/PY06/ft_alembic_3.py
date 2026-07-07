# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_alembic_3.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:05:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:06:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

from alchemy.elements import create_air

print("=== Alembic 3 ===")
print("Accessing alchemy/elements.py using 'from ... import ...' structure")
result = create_air()
print(f"Testing create_air: {result}")
