numbers = []
for i in range(4):
    numbers.append(int(input()))

telemarketer = False

if (numbers[0] in [8, 9]) and (numbers[3] in [8, 9]) and (numbers[1] == numbers[2]):
    telemarketer = True

if (telemarketer):
    print('ignore')
else:
    print('answer')
