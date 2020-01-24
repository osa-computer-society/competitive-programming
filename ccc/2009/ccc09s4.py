import sys, heapq

data = sys.stdin.read().split('\n')

class node:
    def __init__(self):
        self.d = float('inf')
        self.price = float('inf')
        self.adj = []
    
    def __lt__(self, value):
        return self.d < value.d
    
    # def __repr__(self):
    #     return f'node<d={self.d} price={self.price}>'

n = int(data[0])
t = int(data[1])
V = [node() for _ in range(n)]
for a, b, w in [map(int, x.split()) for x in data[2:t+2]]:
    V[a-1].adj.append((b-1, w))
    V[b-1].adj.append((a-1, w))

k = int(data[t+2])
for z, p in [map(int, x.split()) for x in data[t+3:t+3+k]]:
    V[z-1].price = p

d = int(data[t+3+k]) - 1
V[d].d = 0

Q = [V[d]]
while len(Q) > 0:
    u = heapq.heappop(Q)
    for v, d in u.adj:
        if V[v].d > u.d + d:
            V[v].d = u.d + d
            heapq.heappush(Q, V[v])

ans = float('inf')
for u in V:
    if u.d + u.price < ans:
        ans = u.d + u.price

print(ans)
