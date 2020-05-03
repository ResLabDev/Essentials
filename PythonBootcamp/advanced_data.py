# 1. Advanced Numbers

print(hex(12), bin(12))
print(pow(2,4), pow(2,4,3))
print(abs(-3))
print(round(8.1))

import math
print(math.pi)
print(round(math.pi, 4))


# 2. Advanced Strings
s = "hello python"
print(s.capitalize(), s.upper(), s.lower())
print(s.count('o'), s.find('o'))
print(s.center(20, '-'))
print("Hello\tPython")

s = "hello"
print(s.isalnum(), s.isalpha())
print(s.islower(), s.isupper(), s.isspace())
print(s.istitle(), s.endswith('o'), s[-1] == 'o')

s = "This is a beginning of a beautiful friendship!"
print(s.split())
print(s.split('n'))         # Splits at every instance
print(s.partition('i'))     # Splits at the first instance


# 3. Advanced Sets
s = set()
s.add(1)
s.add(2)
print(s)
s.clear()
print(s)

s = {1,2,3}
sc = s.copy()
s.add(4)
print(sc)
print(s.difference(sc))

s1 = {1,2,3}
s2 = {1,4,5}
s1.difference_update(s2)
print(s1)
s1.discard(3)
s1.discard(5)
print(s1)

s1 = {1,2,3,4}
print(s1.intersection(s2))
s1.intersection_update(s2)
print(s1)

s1 = {1,2}
s2 = {1,2,4}
s3 = {5}
print(s1.isdisjoint(s2), s1.isdisjoint(s3), s1.issubset(s2), s2.issuperset(s1))
print(s1.symmetric_difference(s2))
print(s1.union(s2), s1.union(s3))
s1.update(s2,s3)
print(s1)

# 4. Advanced Dictionary
d = {'k1':1, 'k2':2}
b = {x:x**2 for x in range(20)}  # Dictionary comprehension
print(b)
c = {k:v**2 for k,v in zip(['a','b'],range(2))}  # Dictionary comprehension
print(c)
for k in d.items():
    print(k)
for k in d.keys():
    print(k)


# 5. Advanced List
l = [1,2,3]
l.append(4)
print(l, l.count(1), l.count(2), l.count(10))
l2 = l
l.append([9,8])
l2.extend([7,6])
print(l, l2)
print(id(l), id(l2))    # l and l2 at the same memory reference
del(l2)
print(l.index(7))
l.insert(2,'inserted')
print(l)
print(l.pop(), l.pop(0))
l.remove('inserted')
l.extend([3,11,3])
print(l)
l.remove(3)     # Removes just the first instance
print(l)
l.remove([9,8])
l.reverse()
print(l)
l.sort()
print(l)
