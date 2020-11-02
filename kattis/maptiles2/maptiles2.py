quadkey = [int(x) for x in list(input())]
zoom = len(quadkey)
for i in range(zoom):
    if quadkey[i] == 0:
        quadkey[i] = (0, 0)
    elif quadkey[i] == 1:
        quadkey[i] = (1, 0)
    elif quadkey[i] == 2:
        quadkey[i] = (0, 1)
    elif quadkey[i] == 3:
        quadkey[i] = (1, 1)

x = 0
y = 0

for i in range(zoom):
    x += quadkey[i][0] * (2 ** (zoom - i - 1))
    y += quadkey[i][1] * (2 ** (zoom - i - 1))

print("%d %d %d" % (zoom, x, y))
