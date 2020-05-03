# https://github.com/Pierian-Data/Complete-Python-3-Bootcamp/tree/master/13-Advanced%20Python%20Modules

# === COLLECTIONS MODULE ===
# 1. Counter
from collections import Counter

l = [1,1,1,2,121,2,6,3,54,54]
print(Counter(l))

s = "This is a beginning of a beutiful friendship!"
print(Counter(s))

words = s.split()
print(Counter(words))

c = Counter(words)
print(c.most_common(2))

total_words = sum(c.values())
print(total_words)


# 2. defaultdict
#   => automatically creates value in case of key error
from collections import defaultdict

d = {'k1':86}
print(d['k1'])
# print(d['k2'])

d = defaultdict(object)
print(d['k2'])
for item in d:
    print(item)
    
d = defaultdict(lambda : 0)
print(d['k2'])
d['k1'] = 55
for item in d:
    print(item)
    

# 3. OrderedDict
from collections import OrderedDict

d1 = OrderedDict()
d1['a'] = 1
d1['b'] = 2

d2 = OrderedDict()
d2['b'] = 2
d2['a'] = 1

for k,v in d1.items():
    print(k,v)
    
# 4. namedtuple
from collections import namedtuple

t = (1,2,3)
print(t[0])

Dog = namedtuple('Dog', 'age breed name')   # Creating class
myDog = Dog(age=2, breed='Puli', name='Bogáncs')

print(myDog.age, myDog.breed, myDog.name)
print(myDog[0], myDog[1], myDog[2])

# 5. datetime
import datetime

t = datetime.time(5,25,1)
print(t, t.hour, t.minute, t.microsecond)
print(datetime.time.min)
print(datetime.time.resolution)

today = datetime.date.today()
print(today)
print(today.timetuple())
print(today.year, today.month, today.day)
print(datetime.date.min, datetime.date.max, datetime.date.resolution)

d1 = datetime.date(2015,3,11)
print(d1)
d2 = d1.replace(year=1990)
print(d2)

print(d1-d2)
d1 = datetime.date(1978,9,28)
print(datetime.date.today()-d1)


    

