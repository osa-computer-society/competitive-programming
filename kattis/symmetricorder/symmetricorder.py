n = -1
x = 1
while n != 0:
    n = int(input())
    names = []
    for i in range(n):
        names.append(input())
    names = sorted(names, key=len)
    if n != 0: print("SET " + str(x))
    if n % 2 == 0:
        for i in names[::2]:
            print(i)
        for i in names[::-2]:
            print(i)
    elif n % 2 == 1:
        for i in names[::2]:
            print(i)
        for i in names[-2::-2]:
            print(i)
    x += 1
