import math

class Line:
    def __init__(self,coor1,coor2):
        self.coor1 = coor1
        self.coor2 = coor2
    
    def distance(self):
        x1, y1 = self.coor1
        x2, y2 = self.coor2
        
        return math.sqrt((x2-x1)**2 + (y2 - y1)**2)
    
    def slope(self):
        x1, y1 = self.coor1
        x2, y2 = self.coor2
        
        return (y2 - y1) / (x2 - x1)
    
line = Line((3, 2), (8, 10))
print(line.distance())
print(line.slope())

class Cylinder:
    def __init__(self,height=1,radius=1):
        self.height = height
        self.radius = radius
        
    def volume(self):
        return math.pi * self.radius**2 * self.height
    
    def surface_area(self):
        return 2 * math.pi * self.radius * self.height + 2 * math.pi * self.radius**2

cylinder = Cylinder(2,3)
print(cylinder.volume())
print(cylinder.surface_area())

class Account:
    def __init__(self, owner, balance):
        self.owner = owner
        self.balance = balance
    
    def deposit(self, deposit):
        self.balance += deposit
        print("Deposit Accepted")
    
    def withdraw(self, withdraw):
        if self.balance >= withdraw:
            self.balance -= withdraw
            print("Withdrawal Accepted")
        else:
            print("Funds Unavailable!")
    
    def __str__(self):
        return f"Account owner: {self.owner}\nAccount balance: ${self.balance}"
    
acct1 = Account("Jose",100)
print(acct1)
acct1.deposit(50)
acct1.withdraw(75)
acct1.withdraw(500)

