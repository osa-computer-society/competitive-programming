import math
r, c = [int(x) for x in input().split(' ')]
c = r - c
print((c * c * math.pi) / (r * r * math.pi) * 100)
