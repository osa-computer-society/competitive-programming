n = int(input())
cups = {}
for i in range(n):
    x, y = input().split(" ")
    try:
        x = int(x) / 2
        cups[y] = x
    except ValueError:
        y = int(y)
        cups[x] = y

for x in sorted(cups.items(), key=lambda x: x[1]):
    print(x[0])
