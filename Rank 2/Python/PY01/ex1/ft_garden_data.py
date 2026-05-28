# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_garden_data.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:25:09 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/27 17:58:35 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

from typing import TypedDict


class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name: str = name
        self.height: float = height
        self.age: int = age

    def __str__(self) -> str:
        return f"{self.name}: {self.height}cm, {self.age} days old"


class GardenData(TypedDict):
    name: list[str]
    height: list[float]
    age: list[int]


def main() -> int:
    plants: GardenData
    i: int

    plants = {
        'name': ['Rose', 'Sunflower', 'Cactus'],
        'height': [25.0, 80.0, 15.0],
        'age': [30, 45, 120],
    }
    print("=== Garden Plant Registry ===")
    i = 0
    while i < len(plants['name']):
        print(Plant(plants['name'][i], plants['height'][i], plants['age'][i]))
        i += 1
    return 0


if __name__ == "__main__":
    main()
