class Acount:
    def __init__(self):
        self._password = "0000"

    @property                  # Convert class methods to read-only properties.
    def password(self):
        return self._password

    @password.setter           # Make the property "self.password" can be changed. It will be an error without this part.
    def password(self, new_passward):
        self._password = new_passward

    @password.deleter          # Delete the object "self.password" (Note that methods and properties are both object).
    def password(self):
        del self._password
        print('del complite')

andy = Acount()
print(andy.password)          # Don't use "andy.password()"

andy.password = "1234"        # Change "andy.password"
print(andy.password)

del andy.password             # Delelte "andy.password"
try:
    print(andy.password)      # "andy.password" has gone, so it will be an error
except:
    andy.password = "4321"    # Assign a value to "andy.password" to create again
    print(andy.password)
