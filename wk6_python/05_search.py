# Implements linear search for names using `in`
import sys

people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2750",
    "Brian": "+1-541-754-3010",
    "Lolyd": "+1-212-456-7890"
}

name = input("Name: ")
# You don't need to write "for" loop to search name.
# The key is a string, so it was found via the spell checker which is the problem in week 5,
#  and Python has done their best to get to constant time using their built-in searches.
print(people)
print(people.items())  # Convert the dictionary to the list of tuples.

for person in people:   # The iterable variables is the keys in the dictionary.
    print(f"{person}: {people[person]}")

for person, number in people.items():  # Convert the dictionary to the list of tuples for iterating, but the order may not be maintained.
    print(f"{person}: {number}")

if name in people:
    print(f"You found! Number: {people[name]}")
    sys.exit(0)

print("Not found")
sys.exit(1)