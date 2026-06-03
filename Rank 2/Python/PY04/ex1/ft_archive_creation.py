#!/usr/bin/python3

# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_archive_creation.py                            :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 12:09:38 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/03 12:09:38 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


import sys
from typing import IO


def check_fragement(fd: bytes) -> None:
    return (print(fd.decode('utf-8'), end=""))


def trans_data(fd: bytes) -> None:
    i: int
    line: bytes

    line = fd
    i = 0
    while (i < len(line)):
        if (line[i] == 10):
            print('#', end="")
            print(bytes([line[i]]).decode('utf-8'), end="")
        i += 1


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
        print("---")
        check_fragement(fd)
        print("---")
        print(f"File '{av[i]}' closed.")
        print()
        print(f"Transform data: '{av[1]}\n")
        print("---")
        trans_data(fd)
        print("---")
        i += 1
        f.close()
    return (0)


if (__name__ == "__main__"):
    sys.exit(main(len(sys.argv), sys.argv))
