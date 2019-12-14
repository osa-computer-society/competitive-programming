# Problem ID: sssp
# By Alexander Cai
# Complete

import sys, heapq
data = sys.stdin.read().split('\n')
class node:
    def __init__(self):
        self.d = float('inf')
        self.adj = []

    def __lt__(self, value):
        return self.d < value.d

N, M = map(int, data[0].split())
V = [node() for i in range(N)]
V[0].d = 0
for u, v, w in [[int(x) for x in row.split()] for row in data[1:M+1]]:
    V[u-1].adj.append((v-1, w))
    V[v-1].adj.append((u-1, w))

Q = [V[0]]
while len(Q) > 0:
    u = heapq.heappop(Q)
    for v, w in u.adj:
        if V[v].d > u.d + w:
            V[v].d = u.d + w
            heapq.heappush(Q, V[v])

for u in V:
    print(-1 if u.d == float('inf') else u.d)
    