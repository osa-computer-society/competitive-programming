import sys
data = sys.stdin.read().split('\n')

EMPTY = [(x, 4-y) for x in range(5) for y in range(2)] + [(0, 0), (0, 1), (0, 2), (1, 2), (3, 2), (4, 0), (4, 1), (4, 2)]
CRYSTAL = [(1, 0), (2, 0), (2, 1), (3, 0)]

def crystal(m, x, y):
  coords = (x // pow(5, m-1), y // pow(5, m-1))
  if coords in EMPTY or m == 1 and coords in ((1, 1), (2, 2), (3, 1)):
    return False
  if coords in CRYSTAL:
    return True
  return crystal(m-1, x % pow(5, m-1), y % pow(5, m-1))

for m, x, y in [map(int, x.split()) for x in data[1:int(data[0])+1]]:
    print(('empty', 'crystal')[crystal(m, x, y)])