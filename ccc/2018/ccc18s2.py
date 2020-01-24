n = int(input())

rows = []

def test_grid(grid):
    for r in grid:
        if r != tuple(sorted(r)):
            return False

    for c in zip(*grid):
        if c != tuple(sorted(c)):
            return False

    return True

for i in range(n):
    rows.append([int(x) for x in  input().split()])

while not test_grid(rows):
    rows = list(zip(*reversed(rows)))

for row in rows:
    print(' '.join(map(str, row)))