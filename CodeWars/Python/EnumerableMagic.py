# https://www.codewars.com/kata/54599705cbae2aa60b0011a4/train/python

def one(sq, fun): 
    trueCount = 0
    for i in sq:
        if (fun(i)):
            trueCount += 1
        if (trueCount > 1):
            break
    
    return (trueCount == 1)
    
 def one2(sq, fun): 
    return sum(map(fun,sq))==1