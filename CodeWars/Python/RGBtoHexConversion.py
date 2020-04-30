'''
def ValidateColor(color):
    if color > 255: return 255
    elif color < 0: return 0
    else: return color
'''

ValidateColor = lambda x: 255 if x > 255 else (0 if x < 0 else x)

def rgb(r, g, b):
    r = "%0.2X" % ValidateColor(r)
    g = "%0.2X" % ValidateColor(g)
    b = "%0.2X" % ValidateColor(b)
    
    return f"{r}{g}{b}"

strHex = "%0.2X" % 255
print(strHex)

print(rgb(255, 255, 255))
print(rgb(0, 0, 0))

# Solution
def rgb2(r, g, b):
    round = lambda x: min(255, max(x, 0))
    return ("{:02X}" * 3).format(round(r), round(g), round(b))