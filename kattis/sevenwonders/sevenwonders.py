cards = input()
t = 0
c = 0
g = 0
sets = 0
for letter in cards:
    if letter == "T":
        t += 1
    elif letter == "C":
        c += 1
    else:
        g += 1

print(t **2 + c **2 + g **2 + min([t, c, g])*7)
