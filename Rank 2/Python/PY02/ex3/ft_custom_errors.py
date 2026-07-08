# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_custom_errors.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 18:21:15 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/28 19:24:24 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


class GardenError(Exception):
    def __init__(self, msg: str = "Unknown garden error") -> None:
        super().__init__(msg)


class PlantError(GardenError):
    def __init__(self, msg: str = "Unknown plant error") -> None:
        super().__init__(msg)


class WaterError(GardenError):
    def __init__(self, msg: str = "Unknown water error") -> None:
        super().__init__(msg)


def test_plant_error() -> None:
    print("Testing PlantError...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()


def test_water_error() -> None:
    print("Testing WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()


def test_catch_all() -> None:
    print("Testing catching all garden errors...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print()


def main() -> int:
    print("=== Custom Garden Errors Demo ===")
    print()
    test_plant_error()
    test_water_error()
    test_catch_all()
    print("All custom error types work correctly!")
    return (0)


if (__name__ == "__main__"):
    main()
