# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_coordinate_system.py                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 17:08:10 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/29 23:13:27 by agarcia2        ###   ########.fr        #
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


def read_matrix() -> list[list[float]]:
    raw: str
    new: list[str]
    coords: list[float]
    i: int

    while (True):
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")
        new = raw.split(',')
        if (len(new) != 3):
            print("Invalid syntax")
            continue
        coords = []
        i = 0
        try:
            while (i < len(new)):
                coords.append(float(new[i].strip()))
                i += 1
        except ValueError as e:
            print(f"Error on parameter '{new[i].strip()}': {e}")
            continue
        break
    return ([[0.0, 0.0, 0.0, coords[0]],
             [0.0, 0.0, 0.0, coords[1]],
             [0.0, 0.0, 0.0, coords[2]]])


def main() -> int:
    m1: list[list[float]]
    v1: list[float]
    v2: list[float]
    dist: float

    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    m1 = read_matrix()
    v1 = get_matrix(m1)
    print(f"Got a first tuple: {tuple(v1)}")
    print(f"It includes: X={v1[0]}, Y={v1[1]}, Z={v1[2]}")
    print(f"Distance to center: {get_player_pos(m1):.4f}\n")
    print("Get a second set of coordinates")
    v2 = get_matrix(read_matrix())
    dist = get_player_pos([[0, 0, 0, v2[0] - v1[0]],
                           [0, 0, 0, v2[1] - v1[1]],
                           [0, 0, 0, v2[2] - v1[2]]])
    print(f"Distance between the 2 sets of coordinates: {dist:.4f}")
    return (0)


if (__name__ == "__main__"):
    main()
