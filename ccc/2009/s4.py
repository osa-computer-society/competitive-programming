# NOT FINISHED
import sys, heapq

data = sys.stdin.read().split('\n')
n = int(data[0])
t = int(data[1])

class node:
    def __init__(self, i):
        self.i = i
        self.d = float('inf')
        self.price = float('inf')
        self.adj = []
    
    def __lt__(self, value):
        return self.d < value.d
    
    def __repr__(self):
        return f'node<i={self.i} d={self.d} price={self.price}>'

V = [node(i) for i in range(1, n+1)]
for a, b, w in [map(int, x.split()) for x in data[2:t+2]]:
    V[a-1].adj.append((b, w))
    V[b-1].adj.append((a, w))

k = int(data[t+2])
for z, p in [map(int, x.split()) for x in data[t+3:t+3+k]]:
    V[z-1].price = p

d = int(data[t+3+k])
V[d-1].d = 0

Q = [V[d-1]]
while len(Q) > 0:
    u = heapq.heappop(Q)
    for v, d in u.adj:
        if V[v-1].d > u.d + d:
            V[v-1].d = u.d + d

print(V)

ans = float('inf')
for u in V:
    if u.d + u.price < ans:
        ans = u.d + u.price

print(ans)
