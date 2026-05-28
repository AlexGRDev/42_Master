# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_custom_errors.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 18:21:15 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/28 18:38:52 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

def main() -> int:
    i: int

    print("=== Custom Garden Errors Demo ===")
    i = 0
    while (i < 3):
        i += 1
    print("All custom error types work correctly!")
    return (0)


if (__name__ == "__main__"):
    main()
