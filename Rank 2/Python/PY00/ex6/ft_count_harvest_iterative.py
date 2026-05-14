# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_count_harvest_iterative.py                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:15:21 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:15:25 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_count_harvest_iterative():
    days: int
    i: int

    days = int(input(("Days until harvest: ")))
    i = 1
    while (i <= days):
        print(f'days: {i}')
        i += 1
    print("Harvest time !")
