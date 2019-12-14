# CCC '17 S3
# By Alexander Cai
# UNFINISHED

import sys
from collections import defaultdict
data = sys.stdin.read().split('\n')

ls = defaultdict(int) # length -> count
for n in map(int, data[1].split()):
    ls[n] += 1

vals = list(ls.items())
sums = defaultdict(int)
for i in range(len(vals)):
    ln, cnt = vals[i]
    sums[ln*2] += cnt // 2
    for ln1, cnt1 in vals[i+1:]:
        sums[ln+ln1] += min(cnt, cnt1)

ans, nans = 0, 0
for ln in sums.values():
    if ln == ans:
        nans += 1
    elif ln > ans:
        ans = ln
        nans = 1

print(ans, nans)
