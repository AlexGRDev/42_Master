# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plot_area.py                                   :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:13:42 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 11:14:22 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #
def ft_plot_area():
    length: int
    width: int
    result: int

    length = int(input("Enter length: "))
    width = int(input("Enter width: "))
    result = length * width
    print(f'Plot area: {result}')
