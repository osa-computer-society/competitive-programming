scores = [input() for x in range(6)]
wins = scores.count('W')
if wins in [5, 6]:
  print(1)
elif wins in [3, 4]:
  print(2)
elif wins in [1, 2]:
  print(3)
else:
  print(-1)