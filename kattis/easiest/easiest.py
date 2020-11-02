def digitSum(x):
    return sum([int(i) for i in list(str(x))])

answers = []

while True:
    n = int(input())
    if n == 0:
        break
    
    i = 11
    while True:
        if digitSum(i * n) == digitSum(n):
            answers.append(i)
            break
        i += 1

for i in answers:
    print(i)
