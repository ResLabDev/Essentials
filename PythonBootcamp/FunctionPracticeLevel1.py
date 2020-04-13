#OLD MACDONALD: Write a function that capitalizes the first and fourth letters of a name
'''
    old_macdonald('macdonald') --> MacDonald
    Note: 'macdonald'.capitalize() returns 'Macdonald'
'''
def OldMacDonald (name):
    if (len(name) > 3):
        return name[:3].capitalize() + name[3:].capitalize()
    return 'Too short name.'
    


# MASTER YODA: Given a sentence, return a sentence with the words reversed
'''
    master_yoda('I am home') --> 'home am I'
    master_yoda('We are ready') --> 'ready are We'
'''
def MasterYoda (text):
    return ' '.join(text.split()[::-1])


#ALMOST THERE: Given an integer n, return True if n is within 10 of either 100 or 200
'''
    almost_there(90) --> True
    almost_there(104) --> True
    almost_there(150) --> False
    almost_there(209) --> True
'''
def AlmostThere (num):
    return (abs(100-num) <= 10) or (abs(200-num) <= 10)

print (OldMacDonald('macdonald'))
print (OldMacDonald('mac'))

print(MasterYoda('I am home'))
print(MasterYoda('We are ready'))

print(AlmostThere(90))
print(AlmostThere(104))
print(AlmostThere(150))
print(AlmostThere(209))