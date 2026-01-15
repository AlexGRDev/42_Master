def ft_water_reminder():
    days = int(input("Days since the last watering: "))
    if (days >= 2):
        print("Water the plants!")
    else:
        print("Plants are fine")
