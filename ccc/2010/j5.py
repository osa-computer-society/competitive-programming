import sys, heapq
a, b, c, d = map(int, sys.stdin.read().split())

class node:
    def __init__(self, x, y):
        self.d = float('inf')
        self.i = (x, y)
        self.adj = [(x+h, y+v) for h, v in ((1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)) if x+h > 0 and x+h <= 8 and y+v > 0 and y+v <= 8]
    def __repr__(self):
        return f"node<i={self.i}, adj={self.adj} d={self.d}>\n"
    def __lt__(self, value):
        return self.d < value.d

grid = [[node(x, y) for y in range(1, 9)] for x in range(1, 9)]
grid[a-1][b-1].d = 0
# Dijkstra's
Q = [a for lst in grid for a in lst]
heapq.heapify(Q)
while len(Q) > 0:
    u = heapq.heappop(Q)
    for x, y in u.adj:
        v = grid[x-1][y-1]
        if v.d > u.d + 1:
            v.d = u.d + 1

print(grid[c-1][d-1].d)
