# Class example
class EXAMPLE():
    #  "class_attr" and "class_attr_list" are the attributes of the "EXAMPLE" class.
    class_attr, class_attr_list = 0, [1, 2]

    #  "a" and "b" are the attributes of the instance of the "EXAMPLE" class.
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
    def __init__(self, a, b, k, l): # Note that you must define "a" and "b"  to pass them into "__init__()" of the parent class.
        # super() can call the attributes and methods from the parent class.
        # Call "__init__(a, b)" from the parent class to set the attributes of the instance of the parents,
        # so we can use them inside of the child class.
        super(INHERIT, self).__init__(a, b)                             # Call the parent method.
        print(super().class_attr, super().class_attr_list) # Call the parent attributes.
        self.k, self.l = k, l

        # We can rewrite the parent class's methods with the same name.
        # And we can use "self" and "super()" distinguish them.
        self.method(2,5)        
        super().method(2, 5)
        # Here we rewrited "__init__" in this class,
        # that is why we have to use "super(INHERIT, self).__init__(a, b)" instead of "self.__init__(a, b)" above.
        # If we don't change the parent methods in the child class, we can just utilize "self" to use them.

    # We can just pack "a" and "b" using "**kwargs".
    # def __init__(self, k, l, **kwargs):
    #     super().__init__(**kwargs)
    #     self.k, self.l = k, l

    def print_class_name(self):  # Modify the parent method by defining the new method with the same parent method name.
        print(f"This class is inherit from {super().__class__}")
        print(f"This class is {self.__class__}")
        print(f"The properties from the aprent class: \"a\" = {self.a}, \"b\" = {self.b}")
        print(f"The new properties \"k\" = {self.k}, \"l\" = {self.l}")
        print("--------------")

    def print_multiply(self, x, y):
        print(f"x * y = {self.multiply(x, y)}")     # Use the parent method.
        print(f"x * y = {super().multiply(x, y)}")  # Or utilize "super()" to use the parent method.

    # Rewrite the parent class's methods with the same name.
    def method(self, m, n):
        print(f"m = {m}, m = {n}")
        print(f"m + n = {m * n}")
        print("--------------")

ex_inherit = INHERIT(a=100, b=200, k=7, l=8)
ex_inherit.print_class_name()
ex_inherit.method(m=10, n=20)        # We can also use the method from the parent class "EXAMPLE".
ex_inherit.print_multiply(x=5, y=6)
print(ex_inherit.class_attr)

print("\n==========================\n")
# Multi-layer inheritance
class Parent(object):
    def get_inheritance(self):
        return 'Parent'

class Child(Parent):
    def get_inheritance(self):
        parent = super().get_inheritance()
        return ' <- '.join([parent, 'Child'])

class GrandChild(Child):
    def get_inheritance(self):
        parent = super().get_inheritance()
        return ' <- '.join([parent, 'GrandChild'])

c = GrandChild()
print(c.get_inheritance())  # Parent <- Child <- GrandChild

print("\n==========================\n")
# When we use super() to call the parent method in the child class,
#  we will first look for the corresponding method from the nearest parent class.
#  If not found, go to the parent class of the parent class, so on and so forth, until find it
class Parent(object):
    NAME = 'Parent'
    def __str__(self):
        return self.NAME

class Child(Parent):
    NAME = 'Child'
    def __str__(self):
        return super().__str__()

c = Child()
print(c)     # Child

print("\n==========================\n")
# MRO(Method resolution order) is the resolution order when the child class inherits multiple parent classes.
class A(object):
    def method(self):
        return 'Class A'

class B(A):
    def method(self):
        return 'Class B'

class C(A):
    def method(self):
        return 'Class C'

class D(C, B):
    def method(self):
        m = super().method()
        print(m)
        return 'Class D'

# D inherit B and C at the same time, MRO is from left to right in "class D(C, B)", i.e., from C to B.
# "d.method()" will resolute C first, and then print the value and return to leave the function.
d = D()
d.method()       # Class C
# Show MRO
print(D.__mro__) #　(<class '__main__.D'>, <class '__main__.C'>, <class '__main__.B'>, <class '__main__.A'>, <class 'object'>)
print(D.mro())   # (<class '__main__.D'>, <class '__main__.C'>, <class '__main__.B'>, <class '__main__.A'>, <class 'object'>)
# If we use "self.method" in D, D will be resoluted from D itself first.
# If we use "super().method" in D, D will be resoluted from C first.

class D(C, B):
    def method(self):
        # We can change where MRO starts as below:
        m = super(B, self).method()  # "super(B, self)" treats B as "self" and resulote the next class A based on MRO.
        print(m)
        m = super(C, self).method()  # "super(C, self)" treats C as "self" and resulote the next class B based on MRO.
        print(m)
        # Note that here "super(D, self)" is the same as "super()"
        
        return 'Class D'
d = D()
d.method() # Class A
           # Class B