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


def check_fragement(fd: bytes) -> str:
    return (fd.decode('utf-8'))


def trans_data(fd: bytes) -> str:
    i: int
    line: bytes

    line = fd
    i = 0
    while (i < len(line)):
        if (line[i] == 10):
            line = line[:i] + b"#" + line[i:]
            i += 1
        i += 1
        if (len(line) > 0 and line[-1] != 10 and line[-1] != 35):
            line = line + b'#'
    return (check_fragement(line))


def save_file(fd: bytes) -> None:
    new: str
    f: IO[str]

    print("Enter new file name (or empty): ", end="")
    sys.stdout.flush()
    new = sys.stdin.readline().strip('\n')
    if (new != ""):
        print(f"Saving data to '{new}'")
        try:
            f = open(new, 'w', encoding='utf-8')
            f.write(trans_data(fd))
            print(f"Data saved in file {new}")
            f.close()
        except Exception as e:
            print(f"[STDERR] Error opening file '{new}': {e}", file=sys.stderr)
            print("Data not saved.")
    print("Not saving data.")


def main(ac: int, av: list[str]) -> int:
    fd: bytes
    f: IO[bytes]
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
            print(
                f"[STDERR] Error opening file '{av[i]}': {e}",
                file=sys.stderr
            )
            sys.exit(1)
        print("---")
        print(check_fragement(fd), end="")
        print("---")
        print(f"File '{av[i]}' closed.")
        print()
        print(f"Transform data: '{av[1]}\n")
        print("---")
        print(trans_data(fd), end="")
        print("---")
        save_file(fd)
        i += 1
        f.close()
    return (0)


if (__name__ == "__main__"):
    sys.exit(main(len(sys.argv), sys.argv))
