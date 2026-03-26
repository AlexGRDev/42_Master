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
        return f"{self.name} {self.height}cm, {self.age} days old"

    
def main() -> int:
    plants: dict
    i: int

    plants = {
        'name': ['Rose', 'Oak', 'Cactus', 'Sunflower', 'Fern'],
        'height': ['25', '200', '5', '80', '15'],
        'days': ['30', '365', '90', '45', '120']
    }
    print("=== Plant Factory Output ===")
    i = 0
    while (i < 5):
        print(Plant(plants['name'][i], plants['height'][i], plants['days'][i]))
        i += 1
    print(f'\n\nTotal plants created: {i}')
    return (0)


if __name__ == '__main__':
    main()
