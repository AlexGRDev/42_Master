#!/usr/bin/python3

class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age

    def __str__(self: object):
        return f"{self.name}: {self.height}cm, {self.age} days old"


def main() -> int:
    plants: dict
    i: int

    plants = {
        'name': ['Rose', 'sunflower', 'Cactus'],
        'height': ['25', '80', '15'],
        'age': ['30', '45', '120'],
    }
    print("=== Garden Plant Registry ===")
    i = 0
    while i < 3:
        print(Plant(plants['name'][i], plants['height'][i], plants['age'][i]))
        i += 1
    return (0)


if __name__ == "__main__":
    main()
