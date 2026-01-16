def ft_seed_inventory(object, number, type):
    if type == "packets":
        print(f"{object} seeds: {number} packets available")
    elif type == "grams":
        print(f"{object} seeds: {number} grams total")
    elif type == "area":
        print(f"{object} seeds: {number} square area")
    else:
        print(f"{object} seeds: {number} {type}")


def main():
    ft_seed_inventory("tomato", 15, "packets")
    ft_seed_inventory("carrot", 8, "grams")
    ft_seed_inventory("lettuce", 12, "area")
    return (0)


if __name__ == "__main__":
    main()
