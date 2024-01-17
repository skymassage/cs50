# Saves names and numbers to a CSV file

import csv

name = input("Name: ")
number = input("Number: ")

# Change "file = open("phonebook.csv", "a")" to the following line:
with open("file.csv", "a") as file:  # Utilize "with" and indent this code block to prevent us from forgetting to close the file with "file.close()" once finished.
    writer = csv.writer(file)  # Treat this opened file as a CSV file, so that the contents are separated by commas and nicely formatted in rows and columns.
    writer.writerow([name, number])  # "writerow(args)" is to write the "args" into the same row of the CSV file.

    writer = csv.DictWriter(file, fieldnames=["name", "number"]) # Commonly, CSV files have columns with specific names.
                                                                 # "DictWriter" can be used to create CSV files and assign specific names to each column.
                                                                 # "fieldnames" can specify the order of columns.
    writer.writerow({"name": name, "number": number}) # It can avoid accidentally messing up the order of columns like this "writer.writerow([number, name])", two columns has been swapped.
