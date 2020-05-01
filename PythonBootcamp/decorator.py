def func():
    return 1

def hi():
    print("Hi!")
    
hi2= hi
del hi
hi2()

def hello(name="Agent"):
    print("The hello() function has been executed!")
    
    def greet():
        return "\t This is the greet() function inside the hello()"

    def welcome():
        return "\t This is welcome() function inside hello()"
    
    print("Returning a function:")
    
    if name == "Agent":
        return greet
    else:
        return welcome

func = hello()
print(func())

def cool():
    def super_cool():
        return "I am just cool"
    
    return super_cool

cool_func = cool()
print(cool_func())

def run_func(func_name):
    print("Delegating function")
    print(func_name())

run_func(hi2)

# === DECORATOR ===
def new_decorator(original_func):
    def wrap_func():
        print("Some extra code before original function")
        original_func()
        print("Some extra code after original function")
    
    return wrap_func

@new_decorator
def func_needs_decorator():
    print("I want to be decorated!!")

'''
decorated_func = new_decorator(func_needs_decorator)
decorated_func()
'''
func_needs_decorator()
