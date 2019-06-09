a1, a2, a3 = map(int, [input() for x in range(3)])

if a1 + a2 + a3 != 180:
  print('Error')
elif a1 == 60 and a2 == 60:
  print('Equilateral')
elif a1 == a2 or a2 == a3 or a3 == a1:
  print('Isosceles')
else:
  print('Scalene')