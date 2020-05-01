def add(a,b):
    try:
        result = a + b
    except:
        result = -1
        print("Input format error")
    
    return result

# print(add('5',6))
# print("Error Happened")     # It won't be executed in case of error

def OpenTest():
    try:
        f = open("testfile.txt", 'r')
        f.write("New line is added")
    except TypeError:
        print("Type error has happened")
    except OSError:
        print("OS error has happened")
    except:
        print("Undefined error has happened")
    finally:
        print("I always execute")

# OpenTest()

def askInt():
    i = 0
    while True:
        try:
            result = int(input("Give an integer: "))
        except:
            print("That is not a number")
            continue
        else:
            print("Number {} is accepted.".format(result))
            break
        finally:
            i += 1
            print("Iteration is {}. finished.".format(i))

# askInt()

# HOMEWORK

# Problem 3: Write a function that asks for an integer and prints the square of it. Use a while loopa with a try, except, else block to account for incorrect inputs.
def ask():
    wait = True
    while(wait):
        try:
            num = input("Give an integer: ")
            num = int(num)
        except:
            print("Try again, input type is not integer: {}".format(type(num)))
            continue
        else:
            wait = False
    
    print("Square of {}: {}".format(num, num**2))

ask()