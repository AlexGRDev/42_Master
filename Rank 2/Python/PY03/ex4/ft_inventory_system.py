# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_inventory_system.py                            :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: agarcia2 <agarcia2@student.42barcelona.c  +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2026/05/30 13:38:02 by agarcia2         #+#    #+#              #
#    Updated: 2026/05/30 17:10:00 by agarcia2        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #


import sys


def add_item(inventory: dict[str, int], param: str) -> None:
    parts: list[str]
    name: str
    qty: int

    parts = param.split(':')
    if (len(parts) != 2):
        print(f"Error - invalid parameter '{param}'")
        return (None)
    name = parts[0]
    try:
        qty = int(parts[1])
    except ValueError as e:
        print(f"Quantity error for '{name}': {e}")
        return (None)
    if (name in inventory.keys()):
        print(f"Redundant item '{name}' - discarding")
        return (None)
    inventory[name] = qty


def parse_inventory(ac: int, av: list[str]) -> dict[str, int]:
    inventory: dict[str, int]
    i: int

    inventory = {}
    i = 1
    while (i < ac):
        add_item(inventory, av[i])
        i += 1
    return (inventory)


def show_percentages(inventory: dict[str, int], total: int) -> None:
    items: list[str]
    pct: float
    i: int

    items = list(inventory.keys())
    i = 0
    while (i < len(items)):
        pct = round(inventory[items[i]] / total * 100, 1)
        print(f"Item {items[i]} represents {pct}%")
        i += 1


def report_abundance(inventory: dict[str, int]) -> None:
    items: list[str]
    most: str
    least: str
    i: int

    items = list(inventory.keys())
    if (len(items) == 0):
        return (None)
    most = items[0]
    least = items[0]
    i = 1
    while (i < len(items)):
        if (inventory[items[i]] > inventory[most]):
            most = items[i]
        if (inventory[items[i]] < inventory[least]):
            least = items[i]
        i += 1
    print(f"Item most abundant: {most} with quantity {inventory[most]}")
    print(f"Item least abundant: {least} with quantity {inventory[least]}")


def main(ac: int, av: list[str]) -> int:
    inventory: dict[str, int]
    total: int

    print("=== Inventory System Analysis ===")
    inventory = parse_inventory(ac, av)
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    total = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total}")
    if (total > 0):
        show_percentages(inventory, total)
        report_abundance(inventory)
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")
    return (0)


if (__name__ == "__main__"):
    sys.exit(main(len(sys.argv), sys.argv))
