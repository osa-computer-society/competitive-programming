import sys
from bisect import bisect
data = sys.stdin.read().split('\n')
N = int(data[0])
nums = data[1:1+N]
max_len = max(len(s) for s in nums)
nums = [s.zfill(max_len) for s in nums]
max_count = -1

for i in range(max_len):
    t = sorted([int(s[i]) for s in nums])
    j = bisect(t, 0)
    total = 0
    count = 0
    for k in t[j:]:
        total += k
        if total < 10:
            count += 1
        else:
            break
    max_count = max(count, max_count)

print(max_count)