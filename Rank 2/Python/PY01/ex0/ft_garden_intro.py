#!/usr/bin/python3


def main() -> int:
    name: str
    height: float
    age: int

    name = "Rose"
    height = 25.0
    age = 30
    print("=== Welcome to My Garden ===")
    print(f"Plant: {name}")
    print(f"Height: {height}cm")
    print(f"Age: {age} days")
    print("\n\n=== End of Program ===")
    return 0


if __name__ == "__main__":
    main()
