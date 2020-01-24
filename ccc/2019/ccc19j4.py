def ver():
  global grid
  grid = [
    [grid[0][1], grid[0][0]],
    [grid[1][1], grid[1][0]]
  ]

def hor():
  global grid
  grid = grid[::-1]

grid = [
  [1, 2],
  [3, 4]
]

for flip in input():
  if flip == 'H':
    hor()
  elif flip == 'V':
    ver()

for row in grid:
  print(' '.join(str(x) for x in row))