# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_data_alchemist.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 16:00:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/30 17:10:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

import random


def capitalize_all(players: list[str]) -> list[str]:
    result: list[str]
    i: int

    result = []
    i = 0
    while (i < len(players)):
        result.append(players[i].capitalize())
        i += 1
    return (result)


def keep_capitalized(players: list[str]) -> list[str]:
    result: list[str]
    i: int

    result = []
    i = 0
    while (i < len(players)):
        if (players[i][0].isupper()):
            result.append(players[i])
        i += 1
    return (result)


def build_scores(names: list[str]) -> dict[str, int]:
    scores: dict[str, int]
    i: int

    scores = {}
    i = 0
    while (i < len(names)):
        scores[names[i]] = random.randint(1, 1000)
        i += 1
    return (scores)


def keep_high(names: list[str], scores: dict[str, int],
              average: float) -> dict[str, int]:
    high: dict[str, int]
    i: int

    high = {}
    i = 0
    while (i < len(names)):
        if (scores[names[i]] > average):
            high[names[i]] = scores[names[i]]
        i += 1
    return (high)


def main() -> int:
    players: list[str]
    capitalized: list[str]
    scores: dict[str, int]
    average: float

    print("=== Game Data Alchemist ===\n")
    players = ["Alice", "bob", "Charlie", "dylan", "Emma",
               "Gregory", "john", "kevin", "Liam"]
    print(f"Initial list of players: {players}")
    capitalized = capitalize_all(players)
    print(f"New list with all names capitalized: {capitalized}")
    print(f"New list of capitalized names only: {keep_capitalized(players)}")
    scores = build_scores(capitalized)
    print(f"Score dict: {scores}")
    average = sum(scores.values()) / len(scores)
    print(f"Score average is {round(average, 2)}")
    print(f"High scores: {keep_high(capitalized, scores, average)}")
    return (0)


if (__name__ == "__main__"):
    main()
