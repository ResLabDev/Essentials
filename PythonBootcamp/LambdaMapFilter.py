def SquareCalc (num):
    return num**2

inputData = [0, 1, 2, 3, 4, 5]

for item in map(SquareCalc, inputData):
    print(item)

result = list(map(SquareCalc, inputData))
print(result)

def Splicer(str):
    if len(str) % 2 == 0:
        return 'Even String'
    
    return 'Odd String'

names = ['Andrea', 'Nadine', 'VeronaF']
print(list(map(Splicer, names)))

def IsEven(num):
    return num % 2 == 0

result = filter(IsEven, inputData)
for item in result:
    print(item)
    
Cubed = lambda n: n**3
print(Cubed(3), Cubed(5))

binaries = list(map(lambda n: 2**n, inputData))
print(binaries)

evens = list(filter(lambda n: not n%2, inputData))
print(inputData, evens)

firstLetter = list(map(lambda n: n[0], names))
print(firstLetter)

reverseNames = list(map(lambda n: n[::-1], names))
print(reverseNames)