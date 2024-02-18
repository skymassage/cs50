# Class example
class EXAMPLE():
    def __init__(self, a, b):
        self.a , self.b = a, b
        # pass                      # "pass" if you don't decalre any variable here.

    def __call__(self, x, y):
        print(f"x = {x}, y = {y}")
        print(f"x + y = {x + y}")
        print("--------------")

    def print_class_name(self):
        print(f"This class is {self.__class__}")
        print("--------------")

    def method(self, m, n):
        print(f"m = {m}, m = {n}")
        print(f"m + n = {m + n}")
        print("--------------")

    def cite(self):
        print(f"a * b = {self.multiply(self.a, self.b)}")

    def multiply(self, x, y):
        return x * y

ex = EXAMPLE(a=2, b=3)
ex.print_class_name()
ex(x=100, y=200)
ex.method(m=4, n=5)
ex.cite()

print("\n==========================\n")

# Inherit the class "EXAMPLE"
class INHERIT(EXAMPLE):
    def __init__(self, a, b, k, l):
        # Still need to define "a" and "b" in "__init__" to inherit the property "a" and "b" of the parent class "EXAMPLE".
        # Use "super().__init__()" to inherit the perporty of the parent class.
        # Note that you must inherit all the properties of the class, so here you cannot only inherit the property "a" of "EXAMPLE".
        super().__init__(a, b)
        self.k, self.l = k, l

    def print_class_name(self):  # Modify the parent method by defining the new method with the same parent method name.
        print(f"This class is inherit from {super().__class__}")
        print(f"This class is {self.__class__}")
        print(f"The properties from the aprent class: \"a\" = {self.a}, \"b\" = {self.b}")
        print(f"The new properties \"k\" = {self.k}, \"l\" = {self.l}")
        print("--------------")

    def print_multiply(self, x, y):
        super().multiply(x, y)                   # Use "super()" to utilize the parent method.
        print(f"x * y = {self.multiply(x, y)}")

ex_inherit = INHERIT(a=100, b=200, k=7, l=8)
ex_inherit.print_class_name()
ex_inherit.method(m=10, n=20)        # We can also use the method from the parent class "EXAMPLE".
ex_inherit.print_multiply(x=5, y=6)