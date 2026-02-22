def ft_count_harvest_recursive():
    if ft_count_harvest_recursive.days <= 0:
        return
    current = ft_count_harvest_recursive.days
    ft_count_harvest_recursive.days = ft_count_harvest_recursive.days - 1
    ft_count_harvest_recursive()
    print(f"Day: {current}")


ft_count_harvest_recursive.days = int(input("Days until harvest: "))
