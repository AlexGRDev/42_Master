# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plant_growth.py                                :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:25:21 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/27 17:58:59 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


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
        return f"{self.name}: {self.height}cm, {self.age} days old"


def get_info(plant: Plant) -> None:
    print(plant)


def main() -> int:
    garden: Plant
    i: int
    days: int
    total_growth: float

    garden = Plant("Rose", 25, 30)
    i = 0
    days = 7
    while i < days:
        print(f"=== Day {i + 1} ===")
        garden.grow(1)
        garden.age_one_day()
        get_info(garden)
        i += 1
    total_growth = garden.height - garden.base_height
    print(f"Growth this week: +{total_growth}cm")
    return 0


if __name__ == '__main__':
    main()
