# The "__str__" method represents the class objects as a string. 
# "__str__" should be defined in a way that is easy to read and outputs all the members of the class.
# This method is also used as a debugging tool when the members of a class need to be checked.
#"__str__" is called when the following functions are invoked on the object and return a string: print(), str()
# If we have not defined "__str__", then it will call the "__repr__" method. 
# "__repr__" returns a string that describes the pointer of the object by default (if the programmer does not define it).

class MyClassDefault():
    def __init__(self, anyNumber, anyString):
        self.x = anyNumber
        self.y = anyString

class MyClassStr():
    def __init__(self, anyNumber, anyString):
        self.x = anyNumber
        self.y = anyString
    def __str__ (self):
        return 'MyClassStr(x=' + str(self.x) + ', y=' + self.y + ')'

class MyClassRepr():
    def __init__(self, anyNumber, anyString):
        self.x = anyNumber
        self.y = anyString
    def __repr__ (self):
        return 'MyClassRepr(x=' + str(self.x) + ', y=' + self.y + ')'

# "MyClassDefault" shows an example where neither "__str__" nor "__repr__" are defined. 
# Calling "__str__" calls the default "__repr__" method, and they all give the same output, the pointer of our object.
myObject_default = MyClassDefault(12345, "Hello")
print("---------------------------------------Default")
print(myObject_default.__str__())                                    # <__main__.MyClassDefault object at 0x7feae63effd0>
print(myObject_default.__repr__())                                   # <__main__.MyClassDefault object at 0x7feae63effd0>
print(myObject_default)                                              # <__main__.MyClassDefault object at 0x7feae63effd0>
print()


# "MyClassStr" shows the output once you have defined "__str__". 
# When "__str__", print(), or str() are called you will get your defined output. 
# Make note that the "__repr__" output remains the same.
myObject_str = MyClassStr(12345, "Hello")
print("---------------------------------------__str__ method")
print(myObject_str.__str__())                                        # MyClassStr(x=12345, y=Hello)
print(myObject_str)                                                  # MyClassStr(x=12345, y=Hello)
print(str(myObject_str))                                             # MyClassStr(x=12345, y=Hello)
print(myObject_str.__repr__())                                       # <__main__.MyClassStr object at 0x7feae63efe20>

myObject_repr = MyClassRepr(12345, "Hello")
print("---------------------------------------__repr__ method")
print(myObject_repr.__str__())                                       # MyClassRepr(x=12345, y=Hello)
print(myObject_repr)                                                 # MyClassRepr(x=12345, y=Hello)
print(str(myObject_repr))                                            # MyClassRepr(x=12345, y=Hello)
print(myObject_repr.__repr__())                                      # MyClassRepr(x=12345, y=Hello)
