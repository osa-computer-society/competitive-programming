def cookie_count(n, p, c):
  # a is total number of cookies, b is leftover at each level, a + b = total number of current cookies
  a, b = n // p, 0
  total = 0
  while a != 0:
    total += a
    a, b = (a+b) // c, (a+b) % c
  print(total)

cookie_count(10, 2, 5)
cookie_count(12, 4, 4)