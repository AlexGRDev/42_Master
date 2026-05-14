# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_raise_exception.py                             :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 12:12:24 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/14 12:43:44 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

# !/usr/bin/python3

from ex0 import ft_first_exception


def ft_raise_exception(tmp: int) -> int:
    if (tmp > 40):
        raise ValueError(f"{tmp}°C is too hot for plants (max 40°C)")
    if (tmp < 0):
        raise ValueError(f"{tmp}°C is too hot for plants (max 40°C)")
    return (tmp)


def main() -> int
    return (0)
