import sys, heapq
all_data = sys.stdin.read().split('\n')

class node:
    def __init__(self, i):
        self.i = i
        self.d = 0x3f3f3f3f
        self.p = None
        self.k = 0x3f3f3f3f
        self.adj = []
    def __lt__(self, other):
        return self.d < other.d

k, n, m = map(int, all_data[0].split())
V = [node(i) for i in range(n+1)]

for a, b, t, h in (map(int, x.split()) for x in all_data[1:m+1]):
    V[a].adj.append((t, h, b))
    V[b].adj.append((t, h, a))

A, B = map(int, all_data[-1].split())

V[a].d = 0
V[a].k = k

Q = V[:]
heapq.heapify(Q)
while len(Q) > 0:
    u = heapq.heappop(Q)
    for t, h, v in u.adj:
        if V[v].d > u.d + t and u.k - h > 0:
            V[v].d = u.d + t
            V[v].p = u.i
            V[v].k = u.k - h

if V[B].d == 0x3f3f3f3f: print(-1)
else: print(V[B].d)
