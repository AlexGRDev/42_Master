# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_different_errors.py                            :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 12:12:24 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/28 18:13:04 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

def garden_operations(nbr: int) -> object:
    f: object

    try:
        if (nbr == 0):
            return (int("abc"))
        elif (nbr == 1):
            return (nbr / 0)
        elif (nbr == 2):
            f = open("test", "r")
            return (f)
        elif (nbr == 3):
            return ("hello" + nbr)
        return (nbr)
    except (ValueError, ZeroDivisionError, FileNotFoundError, TypeError) as e:
        return (e)


def main() -> int:
    i: int
    result: object
    error_name: object

    print("=== Garden Error Types Demo ===")
    i = 0
    while (i < 5):
        print(f"Testing operation {i}...")
        result = garden_operations(i)
        error_name = result.__class__.__name__
        if (error_name == "str"):
            print(result)
        else:
            print(f"Caught {error_name}: {result}")
        i += 1
    print("Operation completed successfully")
    return (0)


if (__name__ == "__main__"):
    main()
