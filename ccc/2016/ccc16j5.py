qtype = int(input())
n = int(input())
d, p = [sorted(map(int, input().split())) for i in range(2)]

if qtype == 2:
  p = reversed(p)

print(sum(map(max, zip(d, p))))