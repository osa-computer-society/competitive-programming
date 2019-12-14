import sys

data = [int(ln) for ln in sys.stdin.read().split('\n') if ln != '']
G = data[0] # num gates
P = data[1] # num planes
taken = [False] * G

total = 0
for i in range(P):
    k = data[i+2]-1
    while taken[k] and k >= 0:
        k -= 1
    if k < 0:
        break
    taken[k] = True
    total += 1

print(total)
