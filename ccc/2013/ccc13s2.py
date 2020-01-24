# CCC '13 S2
# By Alexander Cai 2019-12-07
# Solved

import sys

data = sys.stdin.read().split('\n')
w = int(data[0])
n = int(data[1])
psa = []
tot = 0
cnt = 0
for i in map(int, data[2:n+2]):
    tot += i
    psa.append(tot)
    if (len(psa) >= 5 and psa[-1] - psa[-5] > w) or (len(psa) < 5 and psa[-1] > w):
        break
    cnt += 1
    
print(cnt)
