# CCC '17 S3
# By Alexander Cai
# UNFINISHED

import sys
data = sys.stdin.read().split('\n')
ls = {}
for n in map(int, data[1].split()):
    if n not in ls:
        ls[n] = 0
    ls[n] += 1

vals = list(ls.items())
sums = {}
for i in range(len(vals)):
    ln, cnt = vals[i]
    if cnt > 1:
        if ln*2 not in sums:
            sums[ln*2] = 0
        sums[ln*2] += cnt // 2
    else:
        for ln1, cnt1 in vals[i+1:]:
            if ln+ln1 not in sums:
                sums[ln+ln1] = 0
            sums[ln+ln1] += min(cnt, cnt1)

ans, nans = 0, 0
for ln in sums.values():
    if ln == ans:
        nans += 1
    elif ln > ans:
        ans = ln
        nans = 1

print(ans, nans)
