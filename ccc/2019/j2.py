ns = []
cs = []

n = int(input())
for i in range(n):
  i, j = input().split()
  ns.append(int(i))
  cs.append(j)

for i in range(n):
  print(cs[i] * ns[i])