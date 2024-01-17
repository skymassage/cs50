print("\n----------------------------------------------------------------------------------------------------------------------\n")

# Read the entire CSV file:
with open("books.csv", "r") as file:
    text = file.read()           # Read the entire contents of "file" to "text". Note that his lines doesn't need the "csv" module.
    print(text)                  # All text in the CSV file is "str" even though it contain numbers.

print("\n----------------------------------------------------------------------------------------------------------------------\n")

# Read the CSV file as a list:
import csv
books = []
with open("books.csv", "r") as file:
    file_reader = csv.reader(file)  # Read the entire contents of "file", and store them in a list row by row.
    for row in file_reader:
        books.append(row)

print(books)
print(file_reader)  # Note that "file_reader" is not a list.

print("\n----------------------------------------------------------------------------------------------------------------------\n")

# Read the CSV file as a list whose elements are dictionaries (where the first row of the file are keys):
import csv
books = []
with open("books.csv", "r") as file:
    file_reader = csv.DictReader(file)  # Read the entire contents of "file", and store them in a list row by row, each row is a dictionary.
                                        # It will treat each element the first row of the CSV file as a key, so the first row will not be read. In this file, "title" and "author" are keys.
    for row in file_reader:
        books.append(row)

print(books)

for book in books:
    print(book["title"])