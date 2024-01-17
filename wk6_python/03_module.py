def main():
    # There are two ways to call the function from other modules.
    # Method 1:
    from formula import square # Note that the name of the imported module cannot start with a number, such as 1_formula is prohibited.
    for i in range(5):
        print(f"The square of {i} is {square(i)}")

    # Method 2:
    import formula
    for i in range(5):
        print(f"The square of {i} is {formula.square(i)}")

# The "__name__" attribute is a Python built-in variable that represents the name of the current file.
# When runing a Python code, if this module  is the main program being executed directly, the interpreter will set "__name__"  to "__main__".
# And if this file is imported as a module, "__name__" will be set to its own file name instead.
print(f"modula.py __name__: {__name__}")

# When a module is imported, the interpreter will execute each line of this module.
# Using the if __name__ == "__main__" condition, you can control which code is executed in different scenarios.
# If it is true, it means that the file is the main program being executed, and then the code in the condition is executed.
# This allows you to import the module without executing certain code in this imported module that you don't want to execute.
if __name__ == "__main__":
    main()
