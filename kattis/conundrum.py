cipher = list(input())
count = 0
for i in range(len(cipher)):
    pos = i % 3
    if pos == 0:
        if cipher[i] != "P":
            count += 1
    elif pos == 1:
        if cipher[i] != "E":
            count += 1
    elif pos == 2:
        if cipher[i] != "R":
            count += 1

print(count)
