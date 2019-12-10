# CCC '10 S1
# By Alexander Cai 2019-12-08
# Solved

import sys

data = sys.stdin.read().split('\n')
n = int(data[0])
if n == 1:
    print(data[1].split()[0])
else:
    h1, h2, h1name, h2name = -1, -1, '', ''
    for name, r, s, d in map(str.split, data[1:n+1]):
        val = 2*int(r) + 3*int(s) + int(d)
        if val > h1 or (val == h1 and name < h1name):
            h2 = h1
            h2name = h1name
            h1 = val
            h1name = name
        elif val > h2 or (val == h2 and name < h2name):
            h2 = val
            h2name = name
    print(h1name)
    print(h2name)
