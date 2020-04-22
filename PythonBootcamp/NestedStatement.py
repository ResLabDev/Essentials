# LEGB Rule: Local Enclosing Global Built-in
x = 25

def printer():
    x = 50
    return x

print(x)
print(printer())
print(x)

# GLOBAL name
name = 'This is a GLOBAL string'

def greet():
    # ENCLOSING name
    name = 'I am LOCAL'

    def hello():
        # LOCAL name
        print('Hello ' + name)
        
    hello

print(name)
greet()

y = 50

def overwrite():
    global y    # Hard to debug, do not use!
    y = 200
    
print(y)
overwrite()
print(y)