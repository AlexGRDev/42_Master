# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_seed_inventory.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:15:50 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:15:52 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if unit == 'packets':
        print(f'{seed_type.capitalize()} seeds: {quantity} {unit} total')
    elif unit == 'grams':
        print(f'{seed_type.capitalize()} seeds: {quantity} {unit} total')
    elif unit == 'area':
        print(
                f"{seed_type.capitalize()} seeds: "
                f"covers {quantity} square meters")
    else:
        print(f' {seed_type.capitalize()} seeds: {quantity} Unknown unit type')
