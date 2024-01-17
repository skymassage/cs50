def square(x):
    return x * x

print(f"formula.py __name__: {__name__}") # This line will be printed even if the file is imported as a module.

if __name__ == '__main__':
    print("Define the function square in module.py") # This line won't be printed if the file is imported as a module.
