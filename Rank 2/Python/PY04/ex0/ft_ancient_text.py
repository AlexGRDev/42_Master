#!/usr/bin/python3

# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_ancient_tex.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 10:42:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/02 10:42:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

import sys
from typing import IO


def check_fragement(fd: bytes) -> None:
    print("---")
    return (print(fd.decode('utf-8'), end=""))
    print("---")


def main(ac: int, av: list[str]) -> int:
    fd: bytes
    f: IO
    i: int

    if (ac != 2):
        print(f"Usage: {sys.argv[0]} <file>\n")
        return (sys.exit(1))
    i = 1
    while (i < ac):
        try:
            print("== Cyber Archives Recovery ===")
            print(f"Accessing file '{av[1]}'\n")
            with open(av[i], 'rb') as f:
                fd = f.read()
        except Exception as e:
            print(f"Error opening file '{av[1]}': {e}")
            sys.exit(1)
        check_fragement(fd)
        print(f"File '{av[i]}' closed.")
        i += 1
    return (0)


if (__name__ == "__main__"):
    sys.exit(main(len(sys.argv), sys.argv))
