n, m = [int(x) for x in input().split(" ")]
vals = {}
for i in range(n):
    i += 1
    for j in range(m):
        j += 1
        try:
            vals[i+j] += 1
        except KeyError:
            vals[i+j] = 1
largest = 0
for i in vals:
    if vals[i] >= largest:
        largest = vals[i]

keys = []
for i in vals:
    if vals[i] == largest:
        keys.append(i)

[print(i) for i in sorted(keys)]
        
