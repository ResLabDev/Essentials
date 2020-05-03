import re

patterns = ["term1", "term2"]
text = "This is a string with term1, but not the other term"

print(re.search("hello", "hello python!"))

for ptrn in patterns:
    print('Searching for "%s" in:\n"%s"' %(ptrn, text))
    
    # Check for match
    if re.search(ptrn, text):
        print("Match was found.")
    else:
        print("No match was found.")
    
    match = re.search(patterns[0], text)
    print(type(match))
    print(match.start())
    print(match.end())
    
    split_term = '@'
    phrase = "What is your email, is it hello@gmail.com?"
    
    splitted_phrase = re.split(split_term, phrase)
    print(splitted_phrase[0])
    print(splitted_phrase[1])
    
    print(re.findall("match", "Here is one match, here is the other match2"))