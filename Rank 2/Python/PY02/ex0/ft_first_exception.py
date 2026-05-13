#!/usr/bin/python3

def input_temperature(temp_str: str) -> int:
    tmp: int

    tmp = int(temp_str)
    return (tmp)

def main() -> int:
    tmp: str

    tmp = '25'
    print("=== Garden Temperature ===")
    print()
    print(f"Input data is '{tmp}'")
    try:
        print(f"Temperature is now {input_temperature(tmp)}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    print()
    tmp = 'abc'
    print(f"Input data is '{tmp}'")
    try:
        print(f"Temperature is now {input_temperature(tmp)}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("All tests completed - program didn't crash!")
    return (0)


if __name__ == "__main__":
    main()
