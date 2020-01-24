# CCC '13 S3
# By Alexander Cai 2019-12-09
# Solved

import sys
data = sys.stdin.read().split('\n')

K = int(data[0])
R = int(data[1])
C = int(data[2])
grid = [list(s) for s in data[3:R+3]]

cnt = {}

def mark(r, c, k):
    if r >= 0 and r <= R-1 and c >= 0 and c <= C-1 and grid[r][c] == '.':
        grid[r][c] = k
        if k not in cnt:
            cnt[k] = 0
        cnt[k] += 1
        mark(r-1, c, k)
        mark(r+1, c, k)
        mark(r, c-1, k)
        mark(r, c+1, k)

i = 0
for row in range(R):
    for col in range(C):
        if grid[row][col] == '.':
            mark(row, col, i)
            i += 1

l = sorted(cnt.values())
rms = 0

while len(l) > 0:
    n = l.pop()
    if K - n < 0:
        break
    K -= n
    rms += 1
    
print(rms, 'room,' if rms == 1 else 'rooms,', K, 'square metre(s) left over')
