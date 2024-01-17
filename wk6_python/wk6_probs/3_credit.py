# check50 cs50/problems/2023/x/sentimental/credit
# submit50 cs50/problems/2023/x/sentimental/credit

def main():
    while True:
        try:
            number = int(input("Change owed: "))
            if number > 0:
                break
        except:
            continue

    if not iscredit(number):
        print("INVALID")
    else:
        head, length = int(str(number)[0:2]), len(str(number))
        if length == 15 and (head in [34, 37]):
            print("AMEX")
        elif length == 16 and (head in range(51, 56)):
            print("MASTERCARD")
        elif (length == 13 or length == 16) and (head in range(40, 50)):
            print("VISA")
        else:
            print("INVALID")

def digit(number, n):
    return number // 10**n % 10

def iscredit(number):
    sum, length = 0, len(str(number))
    for i in range(length):
        if i % 2 == 1:
            product = 2 * digit(number, i)
            if product >= 10:
                sum = sum + digit(product, 0) + digit(product, 1)
            else:
                sum += product
        else:
            sum += digit(number, i)

    if sum % 10 == 0:
        return True
    return False

main()