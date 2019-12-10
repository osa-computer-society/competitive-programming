# Problem ID: dmpg18g1
# By Alexander Cai 2019-12-09
# Solved

import sys

FILLED = -1
EMPTY = 0

data = sys.stdin.read().split('\n')
n, k = map(int, data[0].split())
chairs = [FILLED for _ in range(n)]

for j in map(int, data[1].split()):
    chairs[j-1] = EMPTY

for i, j in enumerate(map(int, data[2].split())):
    if chairs[j-1] == EMPTY:
        chairs[j-1] = FILLED
    else:
        chairs[j-1] = i+1 # index of student

s = []
nremaining = chairs.count(EMPTY)
i = 0
while nremaining > 0:
    if chairs[i] == FILLED:
        pass
    elif chairs[i] == EMPTY:
        if len(s) > 0: 
            s.pop()
            chairs[i] = FILLED
            nremaining -= 1
    else: # student at this index -- underneath them is filled
        s.append(chairs[i]) # add them to stack
        chairs[i] = FILLED
    i = (i+1) % n

print(s[0])
