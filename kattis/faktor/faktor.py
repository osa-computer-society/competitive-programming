from math import ceil

a, i = [int(x) for x in input().split(" ")]

count = a * i
while ceil(count/a) >= i:
    count -= 1

print(count+1)
