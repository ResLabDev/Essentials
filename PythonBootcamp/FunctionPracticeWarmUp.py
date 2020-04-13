# LESSER OF TWO EVENS: Write a function that returns the lesser of two given numbers if both numbers are even, but returns the greater if one or both numbers are odd
'''
    lesser_of_two_evens(2,4) --> 2
    lesser_of_two_evens(2,5) --> 5
'''
def LesserOfTwoEvens (a, b):
    # Both are even
    if a % 2 == 0 and b % 2 == 0:
        return min(a,b)
    # One or both are odd
    else:
        return max(a,b)


# ANIMAL CRACKERS: Write a function takes a two-word string and returns True if both words begin with same letter
'''
    animal_crackers('Levelheaded Llama') --> True
    animal_crackers('Crazy Kangaroo') --> False
'''
def AnimalCrackers (text):
    wordList = text.split()
    return wordList[0][0] == wordList[1][0]


# MAKES TWENTY: Given two integers, return True if the sum of the integers is 20 or if one of the integers is 20. If not, return False
'''
    makes_twenty(20,10) --> True
    makes_twenty(12,8) --> True
    makes_twenty(2,3) --> False
'''
def MakesTwenty (a, b):
    return a==20 or b==20 or (a+b) == 20

print(LesserOfTwoEvens(24,16))
print(LesserOfTwoEvens(24,15))
print(LesserOfTwoEvens(11,23))

print(AnimalCrackers('Levelheaded Llama'))
print(AnimalCrackers('Crazy Kangaroo'))

print(MakesTwenty(20,10))
print(MakesTwenty(12,8))
print(MakesTwenty(2,3))