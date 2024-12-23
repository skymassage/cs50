print("------------------------------------ The original function without any decorator")
def example():
    """

    Hello world! I'm the Docstring.

    """
    print("")
example()
print(f"The function name: {example.__name__}")
print(f"The docstring inside the function: {example.__doc__}")  # Show a docstring which is a string literal specified in source code that is used, like a comment, to document a specific segment of code.

print("------------------------------------ Without \"@wraps\"")
def decorator_without_wraps(f):
    def wrapper(*args, **kwargs):
        print("Decorator without @wraps")
        return f(*args, **kwargs)
    return wrapper

@decorator_without_wraps
def example():
    """

    Hello world! I'm the Docstring.

    """
    print("")
example()
print(f"The function name: {example.__name__}")                # The function name "example" change to "wrapper" after using the decorator
print(f"The docstring inside the function: {example.__doc__}") # And the docstring is gone after using the decorator.

print("------------------------------------ With \"@wraps\"")
# When decorator is implemented, the decorated function is actually another function (function attributes such as function name will change).
# In order not to be affected, we can use the "@wraps" decorator to eliminate such side effects.
from functools import wraps    # Use "wraps" from "functools"

def decorator_with_wraps(f):
    @wraps(f)                           # Use "@wraps" to
    def wrapper(*args, **kwargs):
        print("Decorator with @wraps")
        return f(*args, **kwargs)
    return wrapper

@decorator_with_wraps
def example():
    """

    Hello world! I'm the Docstring.

    """
    print("")
example()
print(f"The function name: {example.__name__}")                 # The function name is preserved thanks to "@wraps".
print(f"The docstring inside the function: {example.__doc__}")  # The docstring is preserved thanks to "@wraps".
# When writing a decorator, it is best to add "@wraps" before implementation, which can retain the name and docstring of the original function.
