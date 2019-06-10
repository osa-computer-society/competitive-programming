from math import *
h, v = [int(x) for x in input().split(" ")]
print(ceil(h / sin(radians(v))))
