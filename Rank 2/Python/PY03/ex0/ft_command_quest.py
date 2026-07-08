# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_command_quest.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 10:08:10 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/29 10:25:09 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


import sys


def main(ac: int, av: list[str]) -> int:
    i: int

    print("=== Command Quest ===")
    print(f"Program name: {av[0]}")
    if (ac < 2):
        print("No arguments provided!")
    i = 1
    while (i < ac):
        print(f"Argument {i}: {av[i]}")
        i += 1
    print(f"Total arguments: {ac}")
    return (0)


if (__name__ == "__main__"):
    sys.exit(main(len(sys.argv), sys.argv))
