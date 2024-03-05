
class OuterClass:
    def __init__(self):
        self.inner_instance = self.InnerClass() # Instantiate inner class, and use "self." because InnerClass is nested inside OuterClass.

    def reveal(self):
        self.inner_instance.inner_display("Call InnerClass's function from OuterClass")

    class InnerClass:
        def inner_display(self, msg):
            # var = OuterClass.inner_instance # It is an infinite loop, and will be errors.
                                              # Because InnerClass is assigned to in OuterClass, you cannot assign OuterClass in InnerClass
            print(msg)


print("--------------------------------------------------Visit the inner class")
outer_obj = OuterClass()
outer_obj.reveal()
OuterClass().InnerClass().inner_display("Call InnerClass's method directly")
inner_obj = outer_obj.InnerClass() # or "inner_obj = OuterClass().InnerClass()", "inner_obj = outer_obj.inner_instance"
inner_obj.inner_display("Just Print It!")

# Inner classes cannot directly use the attributes and methods of outer classes
class OuterClass:
    def __init__(self):
        self.outer_var = 10
    
    def outer_method(self):
        print("This is the outer method")
    
    class InnerClass:
        def __init__(self, outer_instance):
            self.outer_instance = outer_instance
        
        def inner_method(self):
            print("This is the inner method")
            print("Outer var:", self.outer_instance.outer_var)

print("--------------------------------------------------Use the outer class's attributes and methods in the inner class")
outer_obj = OuterClass()
inner_obj = OuterClass.InnerClass(outer_obj) # Create the inner class object and pass the instance of the outer class to the inner class.
inner_obj.inner_method()
inner_obj.outer_instance.outer_method() # Here is access the inner class's attribute to use the outer method.

# Nested class
class OuterClass:
    def __init__(self):
        self.inner_instance = self.InnerClass()
        self.innerinner_instance = self.inner_instance.InnerInnerClass()

    def show_classes(self):
        print("This is Outer class")

    class InnerClass:
        def __init__(self):
            self.innerinner_instance = self.InnerInnerClass()

        def inner_display(self):
            print("This is Inner class")

        class InnerInnerClass:
            def inner_inner_display(self):
                print("This is multilevel InnerInner class")

print("--------------------------------------------------Nested class")
outer_obj = OuterClass()
inner_obj = outer_obj.InnerClass()
inner_obj.inner_display()
innerinner_obj = inner_obj.InnerInnerClass() # or "innerinner_obj = OuterClass().InnerClass().InnerInnerClass()"
innerinner_obj.inner_inner_display()