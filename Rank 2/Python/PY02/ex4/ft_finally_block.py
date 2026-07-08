# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_finally_block.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 19:24:24 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/28 19:24:24 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


class GardenError(Exception):
    def __init__(self, msg: str = "Unknown garden error") -> None:
        super().__init__(msg)


class PlantError(GardenError):
    def __init__(self, msg: str = "Unknown plant error") -> None:
        super().__init__(msg)


def water_plant(plant_name: str) -> None:
    if (plant_name != plant_name.capitalize()):
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")
    print(f"Watering {plant_name}: [OK]")


def test_watering_system(plants: list[str]) -> None:
    i: int

    print("Opening watering system")
    try:
        i = 0
        while (i < len(plants)):
            water_plant(plants[i])
            i += 1
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")


def main() -> int:
    print("=== Garden Watering System ===")
    print()
    print("Testing valid plants...")
    test_watering_system(["Tomato", "Lettuce", "Carrots"])
    print()
    print("Testing invalid plants...")
    test_watering_system(["Tomato", "lettuce"])
    print()
    print("Cleanup always happens, even with errors!")
    return (0)


if (__name__ == "__main__"):
    main()
