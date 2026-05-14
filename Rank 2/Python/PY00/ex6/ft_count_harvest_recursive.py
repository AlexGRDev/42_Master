# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_count_harvest_recursive.py                     :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:15:34 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:15:36 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_count_harvest_recursive():
    days: int

    days = int(input("Days until harvest: "))

    def ft_recursive(n):
        if n <= 0:
            return
        ft_recursive(n - 1)
        print(f"Day: {n}")
    ft_recursive(days)
    print("Harvest time!")
