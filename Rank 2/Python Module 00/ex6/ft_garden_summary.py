def ft_garden_summary():
    name = input("Enter garden name: ")
    plants = int(input("Enter number of plants: "))
    print(f'Garden: {name}')
    if plants <= 25:
        print(f'Plants: {plants}')
    else:
        if plants >= 25:
            print(f'Plants: {plants}')
    print("Status: Growing well!")
