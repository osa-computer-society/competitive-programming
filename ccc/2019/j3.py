
decoded = []

n = int(input())
for i in range(n):
  count = []
  prev = ''

  for j in input():
    if j == prev:
      count[-1][0] += 1
    else:
      prev = j
      count.append([1, j])
  
  decoded.append(' '.join([' '.join([str(k), v]) for k, v in count]))

for j in range(n):
  print(decoded[j])
