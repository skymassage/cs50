# "range" doesn't give you a list of all values all ​​at once.
# In a "for" loop, it gives only one value at a time to reduce memory consumption.
l1 = range(5)
l2 = [2, 3, 0, 1, 4] # Note that "list()" is same as "[]".
l2.sort() # Use ".sort()" automatically sort the list, and the order will be alphabetical if it is a list of strings
l3 = [x for x in range(100)]  # Declare a list without typing each element.
print(l1)
print(l2)
print(l3)
l2[len(l2):] = [5, 6]  # Append many values to the list without ".append()".
# The output below is the same:
name = "world"
number = 123456789.123456
print("hello,", name)   # By default it will add a space between "hello" and "answer".
print("hello, " + name)  # The type of "answer" should be string.
print(f"hello, {name}")  # This is called f-string.
print(f"number = {number} -> number = {number:,.3f}") # f"{var:format}": "var" is the variable and "format" is the description of "var".
                                                      # Here ',' means to adds comma to thousand place; ".3f" means to round numbers to the third decimal place.
print("hello, {}".format(name))
print("{1}, {0}".format(name, "hello"))  # We can specify the order of strings like this.
print("1-----------------------")

print(l2)
for i in range(10, 30, 5):  # "10" is the starting point, "30" is the endpoint (but not including), and increment by "5" (default is 1)
    print(i)
print("2-----------------------")

presidents = [("George Washington", 1789), ("John Adams", 1797), ("Thomas Jefferson", 1801), ("James Madison", 1809)]
for prez, year in presidents:  # The list of tuples is iterable as well.
    print("In {1}, {0} took office".format(prez, year))  #
print("3-----------------------")

for i in range(4):
    print("#", end="")  # The default value for "end" is "\n", that is why it jumps to the next line after printing.
                        # So "end=""" means that there is nothing after printing.
print()
print("#" * 4)  # Utilize "*" to multiply the print statement to repeat "4" times.
print("4-----------------------")

sentence = "Hello, world!"
words = sentence.split()  # split(): split a string into words by treating space characters (including \n, \r, \t, space) as intervals, and store them in a list of word.
print(words)
for word in words:
    for i, c in enumerate(word):  # When your iterable is a string, you'll iterate over every character of the string, but the order may not be maintained.
        print(f"{word[i]}{c}", end="")
print()

if "Hello," in words:  # There is no need to search the word one by one in a list with a loop.
    print(True)

for word in words:
    if "w" in word:    # There is no need to search the character one by one in a string with a loop.
        print("Found:", word)
print("5-----------------------")

# The index of the dictionary is the key.
person = dict()  # You can also just use "{}" to set a dictionary.
person["Carter"], person["David"], person["Brian"] = "+1-617-495-1000", "+1-949-468-2750", "+1-541-754-3010" # Append key-value pairs
print(person)
for name in person: # When iterating over a dictionary in a "for" loop, the variables iterated over are the keys.
    print(name)
print("6-----------------------")

d = {'Apple':400,'Joey':600,'Bella':50,'2th King':10000}
def get_value(key):
    return d[key]

print(sorted(d, key=get_value))
# "sorted" can return a sorted list.
# The key argument in "sorted" allows you to tell Python the method you wish to use to sort items,
# and the order is from smallest to largest or alphabetically.
# Notice that a function called "get_value" is created, and "get_value" is passed in as an argument to "sorted",
# so here "sorted" will return a list sorted according to the values (instead of the keys) of dictionary.

print(sorted(d, key=lambda key:d[key]))
# You can use anonymous functions or lambda functions, so you don't have to create a entirely extra function "get_value".

print(sorted(d, reverse=True)) # The default of "key" means "sorted" sorts the list based on the keys of the dictionary, and "reverse" is the sorting order.
print(sorted(d))               # The default of "reverse" is False.
print("7-----------------------")

# Swaps two integers
x = 1
y = 2
print(f"x is {x}, y is {y}")
x, y = y, x                  # In Python, it doesn't need to create a temporary variable to swap two variables.
print(f"x is {x}, y is {y}")

# Another example:
people = [{"name": "Harry", "house": "Gryffindor"},
          {"name": "Cho", "house": "Ravenclaw"},
          {"name": "Draco", "house": "Slytherin"}]
people.sort(key=lambda person: person["name"])      # The ".sort()" method doesn't return value.
print(people)
people.sort(key=lambda person: person["house"])
print(people)
print("8-----------------------")

# Compares two strings
s = input("s: ")
t = input("t: ")
if s == t:         # For strings in C, "==" is used to compare their address.
    print("Same")  # Python allows you to compare two strings without examining strings character by character as in C.
else:
    print("Different")
print("9-----------------------")

# Averages three numbers using a list and a loop with "+" operator
scores = []
for i in range(3):
    score = int(input("Score: "))
    scores += [score]              #  same as scores.append()
average = sum(scores) / len(scores)
print(f"Average: {average:.50f}")  # Show the 50 significant digits, and 'f' indicates to treat the variable as a floating point value.
print("10-----------------------")

# "input", by design, always returns a string of text.
x, y = input("x: "), input("y: ")  # Transfer the inputs as integer: x, y =  int(input("x: ")), int(input("y: "))
print(x + y)
print("11-----------------------")

# It's possible to have certain types of values not only have properties or attributes inside of them but have functions as well.
# In Python, these values are known as "objects".
# In C, we could create a struct where you could associate multiple variables inside a single self-created data type.
# In Python, we can do this and also include functions in a self-created data type.
# When a function belongs to a specific object, it is known as a "method".
s = input("Do you agree? ")
s= s.lower() # The object "s" has the types of functions.
if s in ["y", "yes"]:    # same as: if s. == "y" or s == "yes":
    print("Agreed.")
elif s in ["n", "no"]:   # same as: elif s == "n" or s == "no":
    print("Not agreed.")
print("12-----------------------")


# Set is a data type which is an unordered collection with no duplicate elements.
# Use the method ".add()" and ".remove()" to add and remove elements from a set, and ".len()" to find the set's size.
s = set() # Define an empty set using "set()" or "{}". You can create a non-empty set like this: s = {1, 2, 3, 4}
s.add(1), s.add(2), s.add(3), s.add(4)
s.add(3), s.add(1) # Despite adding 3 and 1 to the set twice, each item can only appear once in a set.
s.remove(2)
print(s)
print(f"The set has {len(s)} elements.")
# print(s[0]) # Set cannot use index to access the element of a set.
# But sets are iterable:
for element in s:
    print(element)
# Note that dictionaries and sets are unordered, and strings and tuples are immutable,
# where mutable means that once a sequence has been defined, we can change individual elements of that sequence,
# and ordered means that the order of the objects matters. Note that "len()" works on all sequences (tuple, list, dict, set string) in python.
