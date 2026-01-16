def is_input():
    days = int(input("Days until harvest: "))
    ft_count_harvest_recursive(1, days)


def ft_count_harvest_recursive(n, days):
    if n > days:
        print("Harvest time!")
        return
    print(f'Days: {n}')
    ft_count_harvest_recursive(n + 1, days)
