# check50 cs50/problems/2023/x/sentimental/cash
# submit50 cs50/problems/2023/x/sentimental/cash

while True:
    try:
        cents = float(input("Change owed: "))
        if cents >= 0:
            break
    except:
        continue

cents *= 100

quarters = cents // 25
cents -= quarters * 25

dimes = cents // 10
cents -= dimes * 10

nickles = cents // 5
cents -= nickles * 5

pennies = cents // 1
cents -= pennies * 1

print(int(quarters + dimes + nickles + pennies))