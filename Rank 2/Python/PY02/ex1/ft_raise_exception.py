# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_raise_exception.py                             :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 12:12:24 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 20:27:50 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

# !/usr/bin/python3

from typing import Any


def ft_raise_exception(tmp: int) -> int:
    if (tmp > 40):
        raise ValueError(f"{tmp}°C is too hot for plants (max 40°C)")
    if (tmp < 0):
        raise ValueError(f"{tmp}°C is too cold for plants (min 0°C)")
    return (tmp)


def input_temperature(temp: Any) -> int:
    tmp: int

    tmp = int(temp)
    return (ft_raise_exception(tmp))


def test_temp(tmp: Any) -> None:
    print(f"Input data is '{tmp}'")
    try:
        print(f"Temperature is now: {input_temperature(tmp)}°C")
    except Exception as e:
        print(f"Caught error: {e}")
    print()


def main() -> int:
    print("=== Garden Temperature Checker ===")
    print()
    test_temp('25')
    test_temp('abc')
    test_temp('100')
    test_temp('-50')
    print("All tests completed - program didn't crash!")
    return (0)


if (__name__ == "__main__"):
    main()
