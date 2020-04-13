# FIND 33: Given a list of ints, return True if the array contains a 3 next to a 3 somewhere.
''' 
    has_33([1, 3, 3]) → True
    has_33([1, 3, 1, 3]) → False
    has_33([3, 1, 3]) → False
'''
def Has33 (nums):
    for i in range(0,len(nums)-1):
        if nums[i:i+2] == [3,3]:
            return True
    
    return False


# PAPER DOLL: Given a string, return a string where for every character in the original there are three characters
'''
    paper_doll('Hello') --> 'HHHeeellllllooo'
    paper_doll('Mississippi') --> 'MMMiiissssssiiippppppiii'
'''
def PaperDoll (str):
    result = ''
    for char in str:
        result += 3*char
        
    return result


#BLACKJACK: Given three integers between 1 and 11, if their sum is less than or equal to 21, return their sum.
# If their sum exceeds 21 and there's an eleven, reduce the total sum by 10. Finally, if the sum (even after adjustment) exceeds 21, return 'BUST
'''
    blackjack(5,6,7) --> 18
    blackjack(9,9,9) --> 'BUST'
    blackjack(9,9,11) --> 19
'''
def BlackJack (a, b, c):
    result = sum((a,b,c))
    if result <= 21:
        pass
    elif result <= 31 and 11 in (a,b,c):
        result -= 10
    else:
        return 'BUST'
    
    return result
        

# SUMMER OF '69: Return the sum of the numbers in the array, except ignore sections of numbers starting with a 6 and extending to the next 9 (every 6 will be followed by at least one 9).
# Return 0 for no numbers.
'''
    summer_69([1, 3, 5]) --> 9
    summer_69([4, 5, 6, 7, 8, 9]) --> 9
    summer_69([2, 1, 6, 9, 11]) --> 14
'''
def Summer69(arr):
    total = 0
    addFlag = True
    
    for num in arr:
        if addFlag:
            if num != 6:
                total += num
            else:
                addFlag = False
        else:
            if num == 9:
                addFlag = True
    
    return total
    
# SPY GAME: Write a function that takes in a list of integers and returns True if it contains 007 in order
'''
    spy_game([1,2,4,0,0,7,5]) --> True
    spy_game([1,0,2,4,0,5,7]) --> True
    spy_game([1,7,2,0,4,5,0]) --> False
'''
def SpyGame(arr):
    pattern = [0, 0, 7, 'x']
    
    for num in arr:
        if num == pattern[0]:
            pattern.pop(0)
        if len(pattern) == 1:
            return True
    
    return False


# COUNT PRIMES: Write a function that returns the number of prime numbers that exist up to and including a given number
'''
    count_primes(100) --> 25
'''
def CountPrimes (num):
    if num < 2:
        return 0
    
    primes = [2]
    x = 3
    
    while x <= num:
        #for y in range(3,x,2):      # Test all odd factors from 3
        for y in primes:            # Test all odd factors from 3 => Faster by using the primes list
            if x % y == 0:          # Not prime
                break
        else:                       # Prime found (for-else statement)
            primes.append(x)
        
        x += 2
        
    print(primes)
    
    return len(primes)
    

print(Has33([1, 3, 3]))
print(Has33([1, 3, 1, 3]))
print(Has33([3, 1, 3]))

print(PaperDoll('Hello'))
print(PaperDoll('Mississippi'))

print(BlackJack(5,6,7))
print(BlackJack(9,9,9))
print(BlackJack(9,9,11))

print(Summer69([1, 3, 5]))
print(Summer69([4, 5, 6, 7, 8, 9]))
print(Summer69([2, 1, 6, 9, 11]))
print(Summer69([2, 1, 6, 11, 9]))

print(SpyGame([1,2,4,0,0,7,5]))
print(SpyGame([1,0,2,4,0,5,7]))
print(SpyGame([1,7,2,0,4,5,0]))

print(CountPrimes(100))