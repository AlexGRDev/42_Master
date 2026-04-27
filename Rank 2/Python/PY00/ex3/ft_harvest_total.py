def ft_harvest_total():
    day1: int
    day2: int
    day3: int
    harvest: int

    day1 = int(input("Day 1 harvest: "))
    day2 = int(input("Day 2 harvest: "))
    day3 = int(input("Day 3 harvest: "))
    harvest = day1 + day2 + day3
    print(f'Total harvest: {harvest}')
