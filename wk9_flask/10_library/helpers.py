import random
from string import ascii_letters # "ascii_letters" is the sting "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".

# Generate a random lowercase string of length "len".
def random_string(len):
    string = ""
    for _ in range(len):
        string += random.choice(ascii_letters) # "random.choice" returns a randomly selected element from the specified sequence (string, range, list, tuple or any other kind of sequence).
    return string.lower()
