# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_harvest_total.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:14:35 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:14:37 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_harvest_total() -> None:
    day1: int
    day2: int
    day3: int
    harvest: int

    day1 = int(input("Day 1 harvest: "))
    day2 = int(input("Day 2 harvest: "))
    day3 = int(input("Day 3 harvest: "))
    harvest = day1 + day2 + day3
    print(f'Total harvest: {harvest}')
