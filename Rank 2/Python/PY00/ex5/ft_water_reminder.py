# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_water_reminder.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:15:09 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:15:13 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_water_reminder():
    days: int

    days = int(input("Days since last watering: "))
    if days > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
