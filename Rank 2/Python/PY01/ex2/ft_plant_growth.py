#!/usr/bin/python3

class Plant:
    def __init__(self: object, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age
        self.base_height = None

    def grow(self: object, amount: float):
        if self.base_height is None:
            self.base_height = self.height
        self.height += amount

    def age_one_day(self: object):
        self.age += 1

    def __str__(self: object):
        return f"{self.name}: {self.height}cm, {self.age} days old"


def get_info(plant: object) -> None:
    print(plant)


def main() -> int:
    garden: object
    i: int
    days: int
    total_growth: None

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
    return (0)


if __name__ == '__main__':
    main()
