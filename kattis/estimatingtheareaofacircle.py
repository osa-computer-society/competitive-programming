import math

while True:
    r, m, c = input().split(" ")
    r = float(r)
    m = int(m)
    c = int(c)

    if (r, m, c) == (0, 0, 0):
        break

    ac = r * r * math.pi
    asq = (r * 2) * (r * 2)
    frac = c / m
    esta = (frac * asq)

    if int(ac) == ac:
        ac = int(ac)
    if int(esta) == esta:
        esta = int(esta)

    print(str(ac) + " " + str(esta))
    
