numSpaces = int(input())
yesterday = input()
today = input()
counter = 0
for i in range(numSpaces):
    if (yesterday[i] == 'C') and (today[i] == 'C'):
        counter += 1

print(counter)
