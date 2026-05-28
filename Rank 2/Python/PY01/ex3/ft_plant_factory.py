# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plant_factory.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:25:30 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/27 17:59:16 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

from typing import TypedDict


class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name: str = name
        self.height: float = height
        self.age: int = age
        self.base_height: float = height

    def grow(self, amount: float) -> None:
        self.height += amount

    def age_one_day(self) -> None:
        self.age += 1

    def __str__(self) -> str:
        return f"{self.name} {self.height}cm, {self.age} days old"


class PlantData(TypedDict):
    name: list[str]
    height: list[float]
    days: list[int]


def main() -> int:
    plants: PlantData
    i: int

    plants = {
        'name': ['Rose', 'Oak', 'Cactus', 'Sunflower', 'Fern'],
        'height': [25.0, 200.0, 5.0, 80.0, 15.0],
        'days': [30, 365, 90, 45, 120]
    }
    print("=== Plant Factory Output ===")
    i = 0
    while i < len(plants['name']):
        print(Plant(plants['name'][i], plants['height'][i], plants['days'][i]))
        i += 1
    print(f'\n\nTotal plants created: {i}')
    return 0


if __name__ == '__main__':
    main()
