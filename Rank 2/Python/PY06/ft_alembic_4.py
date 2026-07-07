# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_alembic_4.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 20:07:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 20:08:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import alchemy

print("=== Alembic 4 ===")
print("Accessing the alchemy module using 'import alchemy'")
result = alchemy.create_air()
print(f"Testing create_air: {result}")

print("Now show that not all functions can be reached")
print("This will raise an exception!")
print(f"Testing the hidden create_earth: {alchemy.create_earth()}")
