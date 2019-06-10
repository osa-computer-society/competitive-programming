x = []
y = []
for i in range(3):
    coord = [int(x) for x in input().split(" ")]
    x.append(coord[0])
    y.append(coord[1])

for i in x:
    if x.count(i) % 2 != 0:
        xC = str(i)
for i in y:
    if y.count(i) % 2 != 0:
        yC = str(i)

print(xC + " " + yC)
