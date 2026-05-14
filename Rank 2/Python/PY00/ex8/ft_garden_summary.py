# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_garden_summary.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:16:13 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:16:15 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_garden_summary() -> None:
    garden: str
    plants: str

    garden = input("Enter garden name: ")
    plants = input("Enter number of plants: ")
    print(f'Garden: {garden}')
    print(f'Plants: {plants}')
    print("Status: Growing well!")
