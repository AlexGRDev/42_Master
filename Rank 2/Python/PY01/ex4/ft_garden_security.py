#!/usr/bin/python3


class SecurePlant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name: str = name
        self.__height: float = 0.0
        self.__age: int = 0
        self.set_height(height)
        self.set_age(age)

    def get_height(self) -> float:
        return self.__height

    def get_age(self) -> int:
        return self.__age

    def set_height(self, value: float) -> None:
        if value < 0:
            print(f"Invalid operation attempted: height {value}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self.__height = value
            print(f"Height updated: {value}cm [OK]")

    def set_age(self, value: int) -> None:
        if value < 0:
            print(f"Invalid operation attempted: age {value} days [REJECTED]")
            print("Security: Negative age rejected")
        else:
            self.__age = value
            print(f"Age updated: {value} days [OK]")

    def __str__(self) -> str:
        return f"{self.name} ({self.__height}cm, {self.__age} days)"


def main() -> None:
    plant: SecurePlant

    print("=== Garden Security System ===")
    plant = SecurePlant("Rose", 25, 30)
    print("Plant created: Rose")
    print()
    plant.set_height(-5)
    plant.set_age(-1)
    print(f"\nCurrent plant: {plant}")


if __name__ == "__main__":
    main()
