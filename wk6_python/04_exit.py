import sys

# Printing command-line arguments, indexing into argv
print(len(sys.argv))
for arg in sys.argv:
    print(arg)          # The first argument "argv[0]" is "<file neme>.py" without "./" unlike in C.

# Exits with explicit value
if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)         # Use "sys.exit(i)" to exit the program with a specific exit code, and you can use the command "echo $?" in the terminal to check it.

print(f"hello, {sys.argv[1]}")
sys.exit(0)