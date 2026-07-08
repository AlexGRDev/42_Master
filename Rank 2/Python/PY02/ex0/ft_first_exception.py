# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_first_exception.py                             :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 11:55:42 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/27 18:05:55 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from typing import Any


def input_temperature(temp_str: str) -> int:
    tmp: int

    tmp = int(temp_str)
    return (tmp)


def test_temp(tmp: Any) -> None:
    print(f"Input data is '{tmp}'")
    try:
        print(f"Temperature is now {input_temperature(tmp)}°C")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    print()


def main() -> int:
    print("=== Garden Temperature ===")
    print()
    test_temp('25')
    test_temp('abc')
    print("All tests completed - program didn't crash!")
    return (0)


if (__name__ == "__main__"):
    main()
