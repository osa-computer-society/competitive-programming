p1 = list(map(int, input().split(' ')))
p2 = list(map(int, input().split(' ')))
t = int(input())

dist = abs(p1[0]-p2[0]) + abs(p1[1] - p2[1])
if t < dist or ((dist - t) % 2 == 1):
  print('N')
else:
  print('Y')