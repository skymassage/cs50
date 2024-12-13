# Class example
class EXAMPLE():
    class_attr, class_attr_list = 0, [1, 2]

    #  "a" and "b" are the attributes of instances and "class_attr" and "class_attr_list" are the attributes of the "EXAMPLE" class.
    def __init__(self, a, b):
        self.a , self.b = a, b      # "self" means the instance created from the "EXAMPLE" class.
        # pass                      # "pass" if you don't decalre any variable here.

    # To write classes where the instances behave like functions and can be called like a function.
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

ex = EXAMPLE(a=2, b=3)  # EXAMPLE is a "class" and "ex" is the instance.
ex.print_class_name()
ex(x=100, y=200)
ex.method(m=4, n=5)
ex.cite()
print("\n==========================\n")

ex = EXAMPLE(a=0, b=0)
print(ex.class_attr, EXAMPLE.class_attr)

# Changing class attributes will influence all instances.
EXAMPLE.class_attr = 1            
print(ex.class_attr, EXAMPLE.class_attr)

# But this is limited to changing class attributes from class, it won't influence all instances if we change class attrubutes from instances.
ex.class_attr = 2
print(ex.class_attr, EXAMPLE.class_attr)

# Note that if the class atrrributes are mutable type, it will influence all instances.
# mutable: list, dict, set
# immutable: tuple, str, boolean, int, float
# When the value of a mutable variable changes, the memory address doesn't change; 
# when the value of an immutable variable changes, the memory address changes.
print(ex.class_attr_list, EXAMPLE.class_attr_list)
ex.class_attr_list.append(3)
print(ex.class_attr_list, EXAMPLE.class_attr_list)
print("\n==========================\n")

# Inherit the class "EXAMPLE"
class INHERIT(EXAMPLE):
    def __init__(self, a, b, k, l):
        # Still need to define "a" and "b" in "__init__" to inherit the property "a" and "b" of the parent class "EXAMPLE".
        # Use "super().__init__()" to inherit the perporty of the parent class.
        # "super()" is used to call the method of the parent class, and we can also use "super()" to call other methods of the parent class.
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
print(ex_inherit.class_attr)