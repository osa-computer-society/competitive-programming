n = int(input())
swifts = list(map(int, input().split()))
semaphores = list(map(int, input().split()))

k = 0
s1, s2 = 0, 0

for i in range(n):
  s1 += swifts[i]
  s2 += semaphores[i]
  if s1 == s2:
    k = i + 1

print(k)
