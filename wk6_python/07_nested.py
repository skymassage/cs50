# Double parentheses
def outer(x):
    def inner(y):
        return x + y
    return inner

add = outer(5)
print(outer(5))
print(add(6))
print(outer(5)(6))  # We can write it directly like this.

print("-----------------------------------------")

# Multiple parentheses
def f(a):
  def g(b):
    def h(c):
      print(f"c={c}")
      return a * b *c
    print(f"b={b}")
    return h
  print(f"a={a}")
  return g
print(f"a * b * c = {f(1)(2)(3)}")
