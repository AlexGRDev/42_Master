def ft_days():
    days: int

    days = int(input("Days until harvest "))
    ft_count_harvest_recursive(days)


def ft_count_harvest_recursive(days):
    days: int

    if days <= 0:
        return
    ft_count_harvest_recursive(days - 1)
    print(f'Day: {days}')
