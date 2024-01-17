# check50 cs50/problems/2023/x/sentimental/mario/more
# submit50 cs50/problems/2023/x/sentimental/mario/more
while True:
    try:
        n = int(input("Height: "))
        if n >= 1 and n <= 8:
            break
    except:
        continue

for i in range(n):
    for j in range(n):
        if j < n - i - 1:
            print(" ", end="")
        else:
            print("#", end="")

    print("  ", end="")

    for j in range(n):
        if j < i + 1:
            print("#", end="")

    print()
