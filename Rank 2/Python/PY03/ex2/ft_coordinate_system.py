# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_coordinate_system.py                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 17:08:10 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/29 18:50:38 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3


def get_matrix(matrix: list[list[float]]) -> list[float]:
    return ([matrix[0][3], matrix[1][3], matrix[2][3]])


def get_player_pos(matrix: list[list[float]]) -> float:
    x: float
    y: float
    z: float

    x, y, z = get_matrix(matrix)
    return (float((x ** 2 + y ** 2 + z ** 2) ** 0.5))


def main() -> int:
    raw: str
    new: list[str]
    coords: list[float]
    matrix: list[list]

    while (True):
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")
        new = raw.split(',')
        if (len(new) != 3):
            print("invalid")
            continue
        i = 0
        while (i < len(new)):
            coords = []
            coords.append(float(new[i].strip()))
            i = 0
            while (i < len(coords)):
                matrix = [[], [], []]
                get_player_pos(matrix[coords[0]], matrix[coords[1]], matrix[coords[3]])
                i += 1
            i += 1
    print(coords)
    return (0)


if (__name__ == "__main__"):
    main()
