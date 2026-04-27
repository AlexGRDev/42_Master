def ft_count_harvest_iterative():
    days: int
    i: int

    days = int(input(("Days until harvest: ")))
    i = 1
    while (i <= days):
        print(f'days: {i}')
        i += 1
    print("Harvest time !")
