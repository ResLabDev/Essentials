# Write a function that computes the volume of a sphere given its radius.
import math
def SphereVolume (rad):
    return (4/3) * math.pi * rad**3

print (SphereVolume(2))

# Write a function that checks whether a number is in a given range (inclusive of high and low)
def IsInRange(num, low, high):
    return num in range(low, high+1)
        
print(IsInRange(9,4,10))

# Write a Python function that accepts a string and calculates the number of upper case letters and lower case letters.
'''
    Sample String : 'Hello Mr. Rogers, how are you this fine Tuesday?'
    Expected Output : 
    No. of Upper case characters : 4
    No. of Lower case Characters : 33
'''
def CalcLetters (str):
    count = {"upper":0, "lower":0}
    for ch in str:
        if ch.isupper():
            count["upper"] += 1
        elif ch.islower():
            count["lower"] += 1
        else:
            pass
        
    return count

str = 'Hello Mr. Rogers, how are you this fine Tuesday?'
letters = CalcLetters(str)
print('Original string: ' + str)
print('No. of Upper case characters : {0}' .format(letters["upper"]))
print('No. of Lower case characters : {0}' .format(letters["lower"]))

# Write a Python function that takes a list and returns a new list with unique elements of the first list.
'''
    Sample List : [1,1,1,1,2,2,3,3,3,3,4,5]
    Unique List : [1, 2, 3, 4, 5]
'''
def UniqueList (a):
    b = []
    for x in a:
        if x not in b:
            b.append(x)
    
    return b

sample = [1,1,1,1,2,2,3,3,3,3,4,5]
print('Input List: {}' .format(sample))
print('Unique List: {}' .format(UniqueList(sample)))


# Write a Python function to multiply all the numbers in a list.
'''
    Sample List : [1, 2, 3, -4]
    Expected Output : -24
'''
def MultiplyList (a):
    result = 1
    for x in a:
        result *= x
        
    return result

print(MultiplyList([1, 2, 3, -4]))


# Write a Python function that checks whether a passed string is palindrome or not.
'''
    Note: A palindrome is word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run.
'''
def CheckPalindrome (str):
    str = str.replace(' ', '')  # This replaces all spaces ' ' with no space ''.
    
    return str == str[::-1]     # Reverse string

print(CheckPalindrome('madam'))
print(CheckPalindrome('nurses run'))


# Write a Python function to check whether a string is pangram or not.
'''
    Note : Pangrams are words or sentences containing every letter of the alphabet at least once.
    For example : "The quick brown fox jumps over the lazy dog"
'''
import string

def IsPangram (str):
    return set(string.ascii_lowercase) <= set(str.lower())
    
print(IsPangram('The quick brown fox jumps over the lazy dog'))