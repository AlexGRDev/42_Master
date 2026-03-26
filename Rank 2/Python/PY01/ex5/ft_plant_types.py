#!/usr/bin/python3


class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name: str = name
        self.height: float = height
        self.age: int = age

    def __str__(self) -> str:
        return f"{self.name}: {self.height}cm, {self.age} days"


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str):
        super().__init__(name, height, age)
        self.color: str = color

    def bloom(self) -> None:
        print(f"{self.name} is blooming beautifully!")

    def __str__(self) -> str:
        s: str = f"{self.name} (Flower): {self.height}cm, "
        s += f"{self.age} days, {self.color} color"
        return s


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        trunk_diameter: float
    ):
        super().__init__(name, height, age)
        self.trunk_diameter: float = trunk_diameter

    def produce_shade(self) -> None:
        shade: int = round(self.trunk_diameter * 1.56)
        print(f"{self.name} provides {shade} square meters of shade")

    def __str__(self) -> str:
        s: str = f"{self.name} (Tree): {self.height}cm, "
        s += f"{self.age} days, {self.trunk_diameter}cm diameter"
        return s


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        harvest_season: str,
        nutritional_value: str
    ):
        super().__init__(name, height, age)
        self.harvest_season: str = harvest_season
        self.nutritional_value: str = nutritional_value

    def __str__(self) -> str:
        s: str = f"{self.name} (Vegetable): {self.height}cm, "
        s += f"{self.age} days, {self.harvest_season} harvest"
        return s

    def nutrition(self) -> None:
        print(f"{self.name} is rich in {self.nutritional_value}")


def load_plants(data: list[dict[str, None]], cls: None) -> None:
    i: int
    p: dict[str, None]
    obj: None

    i = 0
    while i < len(data):
        p = data[i]
        if cls is Flower:
            obj = cls(p["name"], p["height"], p["age"], p["color"])
            print("\n")
            print(obj)
            obj.bloom()
        elif cls is Tree:
            obj = cls(p["name"], p["height"], p["age"], p["trunk"])
            print("\n")
            print(obj)
            obj.produce_shade()
        else:
            obj = cls(
                p["name"], p["height"], p["age"],
                p["season"], p["nutrition"]
            )
            print("\n")
            print(obj)
            obj.nutrition()
        i += 1


def main() -> int:
    plants: dict[str, list[dict[str, None]]]

    plants = {
        "flowers": [
            {"name": "Rose", "height": 25, "age": 30, "color": "red"}
        ],
        "trees": [
            {"name": "Oak", "height": 500, "age": 1825, "trunk": 50}
        ],
        "vegetables": [
            {
                "name": "Tomato", "height": 80, "age": 90,
                "season": "summer", "nutrition": "vitamin C"
            }
        ]
    }
    print("=== Garden Plant Types ===")
    load_plants(plants["flowers"], Flower)
    load_plants(plants["trees"], Tree)
    load_plants(plants["vegetables"], Vegetable)
    return (0)


if __name__ == "__main__":
    main()
