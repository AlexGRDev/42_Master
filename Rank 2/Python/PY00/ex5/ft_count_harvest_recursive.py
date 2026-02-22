
def ft_count_harvest_recursive():
    days: int

    days = int(input("Days until harvest: "))

    def ft_recursive(n):
        if n <= 0:
            return
        ft_recursive(n - 1)
        print(f"Day: {n}")
    ft_recursive(days)
    print("Harvest time!")
