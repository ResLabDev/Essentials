with open('sample.txt', mode='a') as f:
    f.write('\nHello from Python!')
    f.close

with open('sample.txt', mode='r') as f:
    text = f.read()
    f.seek(0)
    textLines = f.readlines()
    f.close

print(text)
print(textLines)
