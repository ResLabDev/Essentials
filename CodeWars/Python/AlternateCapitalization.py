def capitalize(s):
    res = ["", ""]
    i = 0
    for item in s:
        if (i % 2):
            res[0] += item.lower()
            res[1] += item.upper()
        else:
            res[0] += item.upper()
            res[1] += item.lower()
        i += 1

    return res

print(capitalize("abcdef"))

def capitalize2(s):
    result = ['','']
    for i,c in enumerate(s):
        result[0] += c.lower() if i % 2 else c.upper()
        result[1] += c.upper() if i % 2 else c.lower()
    return result

def capitalize3(s):
    s = ''.join(c if i%2 else c.upper() for i,c in enumerate(s))
    return [s, s.swapcase()]