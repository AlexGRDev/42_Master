# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    lambda_spells.py                                  :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/07/02 17:00:00 by agarcia2         #+#    #+#              #
#    Updated: 2026/07/02 17:01:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


from typing import TypedDict


class Artifact(TypedDict):
    name: str
    power: int
    type: str


class Mage(TypedDict):
    name: str
    power: int
    element: str


class MageStats(TypedDict):
    max_power: int
    min_power: int
    avg_power: float


def artifact_sorter(artifacts: list[Artifact]) -> list[Artifact]:
    return sorted(
        artifacts, key=lambda artifact: artifact["power"], reverse=True
    )


def power_filter(mages: list[Mage], min_power: int) -> list[Mage]:
    return list(filter(lambda mage: mage["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda spell: f"* {spell} *", spells))


def mage_stats(mages: list[Mage]) -> MageStats:
    powers = [mage["power"] for mage in mages]
    strongest = max(mages, key=lambda mage: mage["power"])
    weakest = min(mages, key=lambda mage: mage["power"])
    average = round(sum(powers) / len(powers), 2)
    return {
        "max_power": strongest["power"],
        "min_power": weakest["power"],
        "avg_power": average,
    }


if __name__ == "__main__":
    artifacts: list[Artifact] = [
        {"name": "Crystal Orb", "power": 85, "type": "orb"},
        {"name": "Fire Staff", "power": 92, "type": "staff"},
        {"name": "Iron Amulet", "power": 40, "type": "amulet"},
    ]
    mages: list[Mage] = [
        {"name": "Elden", "power": 55, "element": "fire"},
        {"name": "Sylra", "power": 88, "element": "ice"},
        {"name": "Torin", "power": 30, "element": "earth"},
    ]
    spells = ["fireball", "heal", "shield"]

    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts)
    first, second = sorted_artifacts[0], sorted_artifacts[1]
    print(
        f"{first['name']} ({first['power']} power) comes before "
        f"{second['name']} ({second['power']} power)"
    )

    print("\nTesting power filter...")
    filtered = power_filter(mages, 50)
    names = [mage["name"] for mage in filtered]
    print(f"Mages with power >= 50: {names}")

    print("\nTesting spell transformer...")
    print(" ".join(spell_transformer(spells)))

    print("\nTesting mage stats...")
    print(mage_stats(mages))
