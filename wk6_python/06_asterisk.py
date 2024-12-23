# The function has 2 positional arguments: "first", "second" and 2 keyword arguments: "third", "fourth".
def save_ranking(first, second, third=None, fourth=None):
    rank = {}
    rank[1], rank[2] = first, second
    rank[3] = third if third is not None else 'Nobody'
    rank[4] = fourth if fourth is not None else 'Nobody'
    print(rank)    

# Positional arguments cannot be omitted, and must be passed to the correct location.
save_ranking('ming', 'alice') # {1: 'ming', 2: 'alice', 3: 'Nobody', 4: 'Nobody'}
# Pass the 2 positional arguments and 1 keyword argument which can be omitted because it has the default value.
save_ranking('alice', 'ming', third='mike') # {1: 'alice', 2: 'ming', 3: 'mike', 4: 'Nobody'}
# Pass the 2 positional arguments and 2 keyword arguments, but one of them was passed as like positional argument.
save_ranking('alice', 'ming', 'mike', fourth='jim') # {1: 'alice', 2: 'ming', 3: 'mike', 4: 'jim'}

# When use only positional arguments
def save_ranking(*args):
    print(args)
# The arguments passed as positional are stored in a tuple named as args,
# and *args means accepting the arbitrary numbers of positional arguments.
save_ranking('ming', 'alice', 'tom', 'wilson', 'roy') # ('ming', 'alice', 'tom', 'wilson', 'roy')

# When use only keyword arguments
def save_ranking(**kwargs):
    print(kwargs)
# The arguments passed as keyword are stored in a dict named as kwargs,
# and **kwargs means accepting the arbitrary numbers of keyword arguments.
save_ranking(first='ming', second='alice', fourth='wilson', third='tom', fifth='roy') # {'first': 'ming', 'second': 'alice', 'fourth': 'wilson', 'third': 'tom', 'fifth': 'roy'}

# When use both positional arguments and keyword arguments
def save_ranking(*args, **kwargs):
    print(args)     
    print(kwargs)
save_ranking('ming', 'alice', 'tom', fourth='wilson', fifth='roy') # ('ming', 'alice', 'tom')
                                                                   # {'fourth': 'wilson', 'fifth': 'roy'}
# Usually, many open sources use typically used argument names such as *args or **kwargs as variadic arguments name.

# The keyword arguments can not be declared before positional arguments, so following code should raises exceptions:
# def save_ranking(**kwargs, *args):
#     ...

print("--------------------------------------------------------")
# Use * to unpack sequence (like lists, tuples, ...).
primes = [2, 3, 5, 7, 11, 13]
def func(a, b, c, d, e, f): print(f, e, d, c, b, a)
print(*primes)           # 2 3 5 7 11 13
print((*primes,))        # (2, 3, 5, 7, 11, 13)
print(*(*primes,))       # 2 3 5 7 11 13
print((*(*primes,),))    # (2, 3, 5, 7, 11, 13)
func(*primes)             # 13 11 7 5 3 2
print("------------------------")

# But for the function definition, the positional arguments are packed.
def product(*numbers):
    func = lambda x, y: x * y
    iteration = iter(numbers) # "iter" returns an iterator object.
    result = next(iteration)  # "next" returns the first iterated item in the next loop,
                              # so this item will be skipped in the next loop whcih will start iterating from its next item.
    for element in iteration:
        result = func(result, element)

    print(numbers)  # numbers is already packed during the function definition, i.e. number = (numbers,).
    print(*numbers) # Use * to unpack numbers.
    print(result)
    print()

primes = [2, 3, 5, 7, 11, 13]
print(*primes)      # 2 3 5 7 11 13           # *primes
product(*primes)    # (2, 3, 5, 7, 11, 13)    # (*primes,)
                    # 2 3 5 7 11 13           # *(*primes,)
                    # 30030
print(primes)       # [2, 3, 5, 7, 11, 13]    # primes
product(primes)     # ([2, 3, 5, 7, 11, 13],) # (primes,)
                    # [2, 3, 5, 7, 11, 13]    # *(primes,)
                    # [2, 3, 5, 7, 11, 13]    # Because "result = next(it)", "result" is "[2, 3, 5, 7, 11, 13]" and "iteration" is empty.
                                              # So no iteration in the next loop.
print((*primes,))   # (2, 3, 5, 7, 11, 13)    # (*primes,)
product((*primes,)) # ((2, 3, 5, 7, 11, 13),) # ((*primes,))
                    # (2, 3, 5, 7, 11, 13)    # *((*primes,))
                    # (2, 3, 5, 7, 11, 13)    # "result" is similar as "product(primes)", no iteration in the next loop.

print("--------------------------------------------------------")
pair = {"a":1, "b":2, "c":3}
def func(a, b, c): print(c, b, a)
# Unpack dictionary as key arguments during function call.
func(**pair) # 3 2 1


# Pack key arguments in function definition.
def func(**kwargs):
    for i in kwargs:
        print(kwargs[i])
func(a=1, b=2, c= 3) # 1
                     # 2
                     # 3
func(**pair)         # 1
                     # 2
                     # 3

print("--------------------------------------------------------")
# *a and *b will do packing the remaining values except the single unpacked values
# which are assigned other normal variables after unpacking the list or tuple. 
numbers = [1, 2, 3, 4, 5, 6]
*a, = numbers
print(a) # [1, 2, 3, 4, 5, 6]

*a, b = numbers
print(a) # [1, 2, 3, 4, 5]  
print(b) # 6

a, *b, = numbers
print(a) # 1
print(b) # [2, 3, 4, 5, 6]

a, *b, c = numbers
print(a) # 1
print(b) # [2, 3, 4, 5]
print(c) # 6

print("--------------------------------------------------------")
# For two asterisk **
a = {'a': 0,}
ab = {'a': 1, 'b': 2, }
c = {'c': 3, **a, **ab,}
# If the same key exists, the values ​​that appear in the future will be the same,
# which is why "a": 0 will eventually become "a": 1.
print(c)        # {'c': 3, 'a': 1, 'b': 2} 
print(*c)       # c a b
# print(**c)    # Error

print("--------------------------------------------------------")
# Use the positional and keyword arguments which are packed and unpacked.
def func(a, *args, kw1, **kwargs):
    print(a, args, kw1, kwargs, sep='#')

func(1, 2, 3, 4, 5, kw1=6, g=7, f=8, l=9)   # 1 # (2, 3, 4, 5) # 6 # {'g': 7, 'f': 8, 'l': 9}