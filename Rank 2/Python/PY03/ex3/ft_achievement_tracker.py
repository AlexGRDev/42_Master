# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_achievement_tracker.py                         :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 10:33:27 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/30 12:10:31 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

#!/usr/bin/python3

import random


def get_achivments() -> list[str]:
    achivment: list[str]

    achivment = [
        "First Steps", "Master Explorer", "Treasure Hunter", "Boss Slayer",
        "Speed Runner", "Collector Supreme", "Survivor", "Strategist",
        "Untouchable", "World Savior", "Crafting Genius", "Sharp Mind",
        "Unstoppable", "Hidden Path Finder"]
    return (achivment)


def gen_player_achivment(achivment: list[str]) -> set[str]:
    count: int

    count = random.randint(5, 9)
    return (set(random.sample(achivment, count)))


def union_all(sets: list[set[str]], skip: int) -> set[str]:
    result: set[str]
    i: int

    result = set()
    i = 0
    while (i < len(sets)):
        if (i != skip):
            result = result.union(sets[i])
        i += 1
    return (result)


def print_report(names: list[str],
                 sets: list[set[str]], full: set[str]) -> None:
    i: int
    common: set[str]

    i = 0
    while (i < len(names)):
        print(f"Player: {names[i]}, {sets[i]}")
        i += 1
    print(f"All distinct achievements: {union_all(sets, -1)}\n")
    common = sets[0]
    i = 1
    while (i < len(sets)):
        common = common.intersection(sets[i])
        i += 1
    print(f"Common achievements: {common}\n")
    i = 0
    while (i < len(names)):
        print(f"Only {names[i]} has: {sets[i].difference(union_all(sets, i))}")
        i += 1
    i = 0
    while (i < len(names)):
        print(f"\n{names[i]} is missing: {full.difference(sets[i])}")
        i += 1


def main() -> int:
    achievements: list[str]
    names: list[str]
    sets: list[set[str]]

    print("=== Achievement Tracker System ===\n\n")
    achievements = get_achivments()
    names = ["Alice", "Bob", "Charlie", "Dylan"]
    sets = [
        gen_player_achivment(achievements),
        gen_player_achivment(achievements),
        gen_player_achivment(achievements),
        gen_player_achivment(achievements),
    ]
    print_report(names, sets, set(achievements))
    return (0)


if (__name__ == "__main__"):
    main()
