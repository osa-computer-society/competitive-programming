from math import sqrt
i = 4 * sqrt(int(input()))
if str(i)[-2:] == ".0":
    i = int(i)
print(i)
