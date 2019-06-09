q = int(input())
n = int(input())
d = sorted(map(int, input().split()))
p = sorted(map(int, input().split()))

pairs = []
for i in range(n):
  if q == 1: 
    pairs.append((d[i], p[i]))
  if q == 2:
    pairs.append((d[i], p[n-1-i]))

print(sum([max(x[0], x[1]) for x in pairs]))
