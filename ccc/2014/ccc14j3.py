n = int(input())

a = 100
d = 100

for i in range(n):
  x, y = map(int, input().split())
  if x > y:
    d -= x
  elif y > x:
    a -= y

print(a)
print(d)