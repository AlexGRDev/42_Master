# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_data_alchemist.py                              :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 16:00:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/06/01 18:48:07 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


import random


def capitalize_all(players: list[str]) -> list[str]:
    return [p.capitalize() for p in players]


def keep_capitalized(players: list[str]) -> list[str]:
    return [p for p in players if p[0].isupper()]


def build_scores(names: list[str]) -> dict[str, int]:
    return {name: random.randint(1, 1000) for name in names}


def keep_high(names: list[str], scores: dict[str, int],
              average: float) -> dict[str, int]:
    return {name: scores[name]
            for name in names if scores[name] > average}


def main() -> int:
    players: list[str]
    capitalized: list[str]
    scores: dict[str, int]
    average: float

    print("=== Game Data Alchemist ===\n")
    players = ["Alice", "bob", "Charlie", "dylan", "Emma",
               "Gregory", "john", "kevin", "Liam"]
    print(f"Initial list of players: {players}\n")
    capitalized = capitalize_all(players)
    print(f"New list with all names capitalized: {capitalized}")
    print(f"New list of capitalized names only: {keep_capitalized(players)}\n")
    scores = build_scores(capitalized)
    print(f"Score dict: {scores}\n")
    average = sum(scores.values()) / len(scores)
    print(f"Score average is {round(average, 2)}")
    print(f"High scores: {keep_high(capitalized, scores, average)}")
    return (0)


if (__name__ == "__main__"):
    main()
