from cs50 import get_string

text = get_string("Text: ")
length = (len(text))

#declaring variabls
sentences = 0
letters = 0
words = 1

for i in range(length):
    if text[i] == "!" or text[i] == "." or text[i] == "?":
        sentences = sentences + 1

    if (text[i].isalpha()):
        letters = letters + 1

    if (text[i].isspace()):
        words = words + 1

# put into formula and round it
L = (100 * letters) / words
S = (100 * sentences) / words
index = (0.0588 * L - 0.296 * S - 15.85)
x = round(index)

# print tha things
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {x}")