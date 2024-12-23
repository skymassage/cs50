class A():
    def __init__(self, x):
        self.x = x
        pass

class B():
    def __init__(self, x):
        super(A).__init__()
        print(A.x)

b = B(1)