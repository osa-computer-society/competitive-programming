i = int(input())

count = 1

if i > 5:
  n, m = 5, i - 5
else:
  n, m = i, 0

for i in range(10):
  n -= 1
  m += 1
  if n < m:
    break
  else:
    count += 1

print(count)
