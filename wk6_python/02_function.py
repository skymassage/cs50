# It's actually a convention in Python to define a main function, so in Python you don't need prototypes like in C.
def main():
    height = get_height()  # We have not called "main" yet, so it doesn't cause any errors.
    for i in range(height):
        print("#")
        
def get_height():
    while True:  # In Python, there is no "do-while" loop.
        try:  # "try" is utilized to attempt to convert "n" to an integer. If it cannot do so, "except" will print out a message and avoid errors interrupting the program, where "ValueError" is one type of errors.
            n = int(input("Height: "))
            if n > 0:
                break
        except ValueError:  # You can also leave "ValueError" out if you don't know the type of error.
            print("Not an integer")

    return n  # Here it doesn't like C, despite "n" is assigned a value in "while" loop, the scope of "n" is everywhere after loop in "get_height".

main()
