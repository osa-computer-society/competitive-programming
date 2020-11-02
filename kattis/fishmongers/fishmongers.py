n, m = map(int, input().split())
w = sorted(map(int, input().split()))
fms = [] # (num kgs, price)
for i in range(m):
    fms.append([int(x) for x in input().split()])
fms = sorted(fms, key=lambda a: a[1]) # Sort by increasing price

total = 0
while len(w) > 0:
    done = False
    while True:
        if len(fms) == 0: # No fishmongers left
            done = True
            break
        if fms[-1][0] == 0:
            fms.pop()
        else:
            break # We have a valid fishmonger
    if done: break
    total += w.pop() * fms[-1][1]
    fms[-1][0] -= 1

print(total)
