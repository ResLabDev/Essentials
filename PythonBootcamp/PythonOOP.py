# Benefits of OOP
#   1. Modularity for easier test and troubleshooting
#   2. Reuse of code through inheritance
#   3. Flexibility through polymorphism
#   4. Effective problem solving

# === ATTRIBUTES AND METHODS ===
class Dog ():
    # Class object attribute
    # Same for any instance of a class
    # self -> reference keyword to the particular instance of the class
    species = 'mammal'
    
    # User define attributes
    def __init__ (self, myBreed, name, spots):
        # Attribute
        # Take in the argument
        # Assign it using self.attribute_name
        self.breed = myBreed
        self.name = name
        
        # Boolean
        self.spots = spots
    
    # Methods ==> operations / actions inside the class
    def bark (self, number):
        print("WOOF! My name is {} and my number is {}".format(self.name, number))

dog = Dog(myBreed = 'Commondor', name = 'Vaska', spots = False)
print(dog.breed)
print(dog.name)
print(dog.spots)
print(dog.species)
dog.bark(112)

class Circle ():
    # Class object attribute
    pi = 3.14
    
    #User defined attributes
    def __init__ (self, radius=1):
        self.radius = radius
        self.area = radius * radius * Circle.pi # Referencing to Class Object Attribute
        
    def GetCircumference (self):
        return self.radius * self.pi * 2

circle = Circle()
print(circle.radius)
print(circle.GetCircumference())
print(circle.area)


# === INHERITENCE ===
class Animal ():
    def __init__(self):
        print("Animal created")
    
    def WhoAmI (self):
        print("I am an animal")
    
    def Eat (self):
        print("I am eating")
        
animal = Animal()
animal.WhoAmI()
animal.Eat()

# Inheriting from Animal base class
class Cat(Animal):
    def __init__(self):
        Animal.__init__(self)
        print("Cat created")

    # Ovverriding base class methods
    def WhoAmI (self):
        print("I am a Cat")
    
    def Eat (self):
        print("I am a cat, Mahlzeit!")
    
    def Meow (self, name):
        print("Meooow! My name is {}".format(name))
        
cat = Cat()
cat.WhoAmI()
cat.Eat()
cat.Meow("Csíííkee")

# === POLYMORPHISM ===
# Different object classes can share the same method name
class Agent():
    status = True
    
    def __init__(self, name):
        self.name = name
        
    def GetStatus (self):
        statusStr = self.name + " is "
        
        if Agent.status:
            statusStr += "ACTIVE"
        else:
            statusStr += "OVER"
        print(statusStr)
    
    def SetStatus(self, statusFlag):
        Agent.status = statusFlag

class Spy():
    status = True
    
    def __init__(self, name):
        self.name = name
        
    def GetStatus (self):
        statusStr = self.name + " is "
        
        if Spy.status:
            statusStr += "COVERED"
        else:
            statusStr += "BLOWN"
        print(statusStr)
    
    def SetStatus(self, statusFlag):
        Spy.status = statusFlag

agent = Agent("Andrea Parker")
spy = Spy("Verona Feldbusch")
agent.GetStatus()
spy.GetStatus()

# Polimorhism demonstration via loop
print("===")
for strike in [agent, spy]:
    print(type(strike))
    strike.GetStatus()

def StrikeStatus(strike):
    strike.GetStatus()

StrikeStatus(agent)
StrikeStatus(spy)

class FFA():
    status = True
    
    def __init__(self, name):
        self.name = name
    
    # Abstract method, should be implemented in other class
    def GetStatus(self):
        raise NotImplementedError("Subclass must implement this abstract method")

ffa = FFA("Female Federation Agency")
# ffa.GetStatus()

class GUCA(FFA):
    def GetStatus(self):
        print("{} is Global Undercovered agent".format(self.name))
        
class EXDIV(FFA):
    def GetStatus(self):
        print("{} is Executor Division agent".format(self.name))

guca = GUCA("Alexandra Bechtel")
exdiv = EXDIV("Andrea Parker")
guca.GetStatus()
exdiv.GetStatus()

# === SPECIAL MAGIC / DUNDER METHODS ===
class Book():
    def __init__(self, title, author, pages):
        self.title = title
        self.author = author
        self.pages = pages
    
    # Special built-in method at string typcasting call
    # String representation of the book class
    def __str__(self):
        return f"{self.title} by {self.author}"
    
    def __len__(self):
        return self.pages

    def __del__(self):
        print("A Book object has been deleted.")
    
book = Book("Python Bootcamp", "Jose", 200)
print(book) # Without String representation it prints just the memory address
print(len(book))

# Deleting object from memory
del(book)

