# NOT FINISHED

import sys, heapq
all_data = sys.stdin.read().split('\n')

class node:
    def __init__(self):
        self.d = float('inf') # distance
        self.k = float('inf') # amount of hp left
        self.adj = []
    def __lt__(self, other):
        return self.d < other.d

k, n, m = map(int, all_data[0].split())
V = [node() for _ in range(n+1)]

for a, b, t, h in (map(int, x.split()) for x in all_data[1:m+1]):
    V[a].adj.append((t, h, b))
    V[b].adj.append((t, h, a))

A, B = map(int, all_data[m+1].split())

V[A].d = 0
V[A].k = k

Q = V[:]
heapq.heapify(Q)
while len(Q) > 0:
    u = heapq.heappop(Q)
    for t, h, v in u.adj: # time, damage, vertex index
        if V[v].d > u.d + t and u.k > h:
            V[v].d = u.d + t
            V[v].k = u.k - h

if V[B].d == float('inf'): print(-1)
else: print(V[B].d)
