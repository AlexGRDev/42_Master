# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_score_analytics.py                             :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/29 11:30:05 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/29 13:12:16 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

import sys


def ft_score_analytics(scores: list[int]) -> int:
    total: int
    average: float

    total = sum(scores)
    average = total / len(scores)
    print(f"Total players: {len(scores)}")
    print(f"Total score: {total}")
    print(f"Average score: {average:.1f}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")
    return (0)


def main(ac: int, av: list[str]) -> int:
    i: int
    scores: list[int]

    print("=== Player Score Analytics ===")
    scores = []
    i = 1
    while (i < ac):
        try:
            scores.append(int(av[i]))
        except ValueError:
            print(f"Invalid parameter: '{av[i]}'")
        i += 1
    if (not scores):
        print("No scores provided. "
              f"Usage: python3 {sys.argv[0]} ...")
        return (1)
    print(f"Scores processed: {scores}")
    ft_score_analytics(scores)
    return (0)


if (__name__ == "__main__"):
    sys.exit(main(len(sys.argv), sys.argv))
