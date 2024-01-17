# This is the Python version of "dictionary.c" in the "speller" which is the problem of the week 5.
words = set()  # one data structure in python: a "set" is just a collection of values with no duplicates, "set()" is to build an empty collection.

def check(word):
    """Return true if word is in dictionary else false"""
    if word.upper() in words: # "lower()" converts a string into lowercase, and "upper()" is similar to it.
                              # Beside, "capitalize()" is to capitalize the first character of the string.
        return True
    else:
        return False

def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()  # "rstrip()" removes space characters (including \n, \r, \t, space) at the end of the string.
                              # Besides, "lstrip()" is for the start of the string, and "strip()" is for both start and end of the string.
        words.add(word)  # "set" can use "add(value)" to add a new element, or "remove(value)" to remove an element.
    file.close()
    return True

def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words)


def unload():
    """Unloads dictionary from memory, returning true if successful else false"""
    return True
