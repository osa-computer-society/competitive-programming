n = int(input())

grid = []
for i in range(n):
    grid.append([int(x) for x in input().split(' ')])

def valid(g):
    for y in range(n):
        for x in range(n):
            if (x+1 < n):
                if not (g[y][x] < g[y][x+1]):
                    return False
            if (y+1 < n):
                if not (g[y][x] < g[y+1][x]):
                    return False
    return True

while True:
    if not valid(grid):
        grid = [list(arr) for arr in zip(*grid[::-1])]
    else:
        break
    
for flower in grid:
    print(' '.join([str(k) for k in flower]))
