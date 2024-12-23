print("------------------------------------------------Ex1: Decorator")
# A decorator, which is a higher-order function that can modify another function.
# The idea of a decorator is a decorator is going to be a function that takes a function of input
# and returns a modified version of that function as output.
# There's a lot of power in decorators for being able to very quickly take a function and add capability to it

# In this example, "announce" takes a function "f" as input, and will return a new function.
# "announce" wraps up "f" with some additional behavior, and "f" is often called a wrapper function.
# Here is what we call "announce" a decorator, a function that takes another function
# and modifies it by adding some additional capabilities to it, and then gives us back some output.
def announce(f):
    def wrapper():
        print("About to run the function")
        f()
        print("Done with the function")
    return wrapper


# Add the decorator "announce" to the function "hello" below, so "hello" is wrapped inside "announce",
# the role of the decorator "announce" is to accept the input "hello" and provide us with a new function .
@announce
def hello():
    print("Hello, world!")
hello()

print("------------------------------------ Decorate a function without a decorator")
# More specifically, here we show how to decorate a function without a decorator.
def hello():                # Because "hello" has decorated, we redefine it.
    print("Hello, world!")
hello = announce(hello)     # Use "announce" to decorate "hello", or execute "announce(hello)()" directly which is the same as the following.
hello()

print("\n------------------------------------------------Ex2: Multiple decorators")
def a1(func):
    print('1', end=" ")
    def wapper():
        print('1', end=" ")
        func()
    return wapper

def a2(func):
    print('2', end=" ")
    def wapper():
        print('2', end=" ")
        func()
    return wapper

def a3(func):
    print('3', end=" ")
    def wapper():
        print('3', end=" ")
        func()
    return wapper

def b():
    print('go!!!!')

# We must solve (excute) "a3(b)" first and know the changed function, then put it into "a2" and so on...
a1(a2(a3(b)))       # Note that the code inside each decorator, we defined the wrapper to change the input function, and also executed "print".
print()
b()                 # Although we just changed "b" in "a1(a2(a3(b)))", but we didn't assign "b" to "a1(a2(a3(b)))", so "b" wasn't decorated.
b = a1(a2(a3(b)))   # Decorate "b".
b()

print("------------------------------------ Use decorators")
@a1
@a2
@a3     # Same as execute "a1(a2(a3(b)))", but also assign it to "b" (i.e. "b = a1(a2(a3(b)))").
def b():
    print('go!!!!')
print()
b()


print("\n------------------------------------------------Ex3: Multiple decorators without changing the input function")
# In each decorator, we don't change the input function.
def a1(func):
    print('1', end=" ")
    return func

def a2(func):
    print('2', end=" ")
    return func

def a3(func):
    print('3', end=" ")
    return func

def b():
    print('go!!!!')
b = a1(a2(a3(b)))  # Because we didn't change the input function in each decorator, so each returned function from the decorators is still "b".
print()
b()                # So "b" doesn't change.

print("------------------------------------ Use decorators")

@a1
@a2
@a3    # b = a1(a2(a3(b)))
def b():
    print('go!!!!')
print()
b()    # "b" doesn't change.


print("\n------------------------------------------------Ex4: Decorate a function containing a preameter")
def a(func):
    def c(m):
        print('makeup...')
        return func(m)
    return c

def b(msg):
    print(msg)
b = a(b)
b('done!!!!')

print("------------------------------------ Use the decorator")
@a
def b(msg):
    print(msg)
b('done!!!!')

print("\n------------------------------------------------Ex5: Decorate a function containing multiple preameters")
def a(func):
    def inner(*args, **kwargs):
        print(f"The last element of args: {args[-1]}")
        kwargs["new_key"] = (789, "Hi", [3,2,1])
        print(f"New key of *kwargs: {kwargs['new_key']}")
        return func(*args, **kwargs)
    return inner

def b(*args, **kwargs):
    print(args, kwargs)
b = a(b)
b(0, [123, 456], "word", a=1, b=[10, 20, 30], c="hello")

print("------------------------------------ Use the decorator")
@a
def b(*args, **kwargs):
    print(args, kwargs)
b(0, [123, 456], "word", a=1, b=[10, 20, 30], c="hello")

print("\n------------------------------------------------Ex6: Decorator containing parameters, decorats a function containing preameters")
def decorator(a, b):
    def inner(func):
        print(f"This is \"inner\"")
        return func
    print(f"This is \"decorator\", a = {a}, a = {b}")
    return inner

def func(x, y):
    print(f"This is \"func\", and x = {x}, y = {y}")

func = decorator(1, 2)(func)
func(10, 20)

print("------------------------------------ Use the decorator")
@decorator(1, 2)
def func(x, y):
    print(f"This is \"func\", and x = {x}, y = {y}")
func(10, 20)

print("\n------------------------------------------------Ex7: Class decorators")
class DECORATOR():
    def __init__(self, func):
        self.func = func

    def __call__(self):
        print("Class decorator running")
        self.func()
        print("Class decorator ending")

def foo():
    print("Hi!")
foo = DECORATOR(foo)
foo()

print("------------------------------------ Use the class decorator")

@DECORATOR
def foo():
    print("Hi!")

foo()
