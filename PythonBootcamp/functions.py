def Add(a, b):
    return a + b

def SayHello(name):
    return '\nHello ' + name

def DogCheck(str):
    return 'dog' in str.lower()

def PigLatin(word):
    firstchar = word[0]
    
    #Check if vowel
    if firstchar in 'aeiou':
        pigWord = word + 'ay'
    else:
        pigWord = word[1:] + firstchar + 'ay'
        
    return pigWord

# Calculates the 5 % of the summary
def SumPart (a, b, c=0, d=0, e=0):
    return sum((a,b,c,d,e)) * 0.05

# TUPPLE
# *args: => => arbitrary number of arguments for tupples
def SumPart2 (*args):
    result = sum(args) * 0.05
    print(result)
    return result

# DICTIONARY
# **kwargs: => arbitrary number of arguments for dictionaries
def FruitChoice (**kwargs):
    print(kwargs)
    if 'fruit' in kwargs:
        print('The chosen fruit: {}' .format(kwargs['fruit']))
    else:
        print('No fruit in the input')
        
def DisplayArgs (*args, **kwargs):
    print(args, kwargs)
    print(args[0], kwargs['meal'])

def EvenFilter(*args):
    result = []
    for x in args:
        if (x % 2) == 0:
            result.append(x)
    return result

def LetterCase(str):
    result = ''
    for char in str:
        if char.islower():
            result += char.upper()
        else:
            result += char.lower()
    return result

#print(Add(10,5))

#name = input('Your name: ')
#print(SayHello(name))

#print(DogCheck('Where is my DOG?'))
#print(DogCheck('Where is my Cat?'))
#print(PigLatin('latin'))
#print(SumPart(15, 467, 647))
#SumPart2(15, 467, 647)

#FruitChoice(meal="pork", fruit="apple")
#DisplayArgs(15, 467, 647, meal="pork", fruit="apple")

data = EvenFilter(0,1,2,3,4,5)
print(data)
print(LetterCase('Hello From Python!'))
