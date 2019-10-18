# In progress
from collections import namedtuple

Node = namedtuple("Node", ["p", "d"])
inf = float("inf")

# n: intersections
# m: roads
# t: repair stations
# d: distance
n, m, t, d = [int(x) for x in input().split()]

# initialize-single-source
nodes = [Node(None, inf) for i in range(n)]
nodes[0].d = 0

repair_stations = [int(x) for x in input().split()]

roadmap = [[None] * n for i in range(n)]

for i in range(m):
    i, j, k = [int(x) for x in input().split()]
    roadmap[i-1][j-1] = k
    roadmap[j-1][i-1] = k

def dfs(G):
    S = [0]
    discovered = []
    while len(S) > 0:
        u = S.pop()
        if not u in discovered:
            discovered.append(u)
            for i in range(n):
                if G[u][i]:
                    S.append(i)

for row in roadmap:
    print(row)

dfs(roadmap)
