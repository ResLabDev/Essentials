'''
Generator Function: it can send back value and then later resume to pick up where left it off
It allows to generate a sequence of values over time
It automatically suspends and resumes the execution
The benefit is the generator computes one value waits until the next value is called for
    => reduces the memory consumption compared to list(range(x,y)) example
    => it just keeps track, not storing all the (huge) data in the memory
Keyword: "yield"
'''

def create_cubes(n):
    result = []
    for x in range(n):
        result.append(x**3)
    
    return result

for x in create_cubes(10):
    print(x)
    

def generate_cubes(n):
    for x in range(n):
        yield x**3
        
# It stores just the current data to be printed in the memory
for x in generate_cubes(20):
    print(x)

# It can be add to the memory as a list if necessary
list(create_cubes(20))

def gen_fibon(n):
    a = 0
    b = 1
    for i in range(n):
        yield a
        a, b = b, a+b

fib = gen_fibon(10)

print(next(fib))
print(next(fib))
print(next(fib))
print(next(fib))
print(next(fib))
print(next(fib))
print(next(fib))

str = "Hello"
str = iter(str)     # Make string iterable
print(next(str))
print(next(str))
print(next(str))

# === HOMEWORK ===
# Problem 1: Create a generator that generates the squares of numbers up to some number N.
def gen_squares(n):
    for i in range(n):
        yield i**2

for x in gen_squares(10):
    print(x)

# Problem 2: Create a generator that yields "n" random numbers between a low and high number (that are inputs).
#            Note: Use the random library. For example:
def rand_num(low, high, n):
    import random
    
    for i in range(n):
        yield random.randint(low, high)

rand_int = rand_num(1, 10, 10)
print(next(rand_int))
print(next(rand_int))
print(next(rand_int))

# Extra credit
my_list = [1,2,3,4,5]

gencomp = (item for item in my_list if item > 3)

for item in gencomp:
    print(item)


