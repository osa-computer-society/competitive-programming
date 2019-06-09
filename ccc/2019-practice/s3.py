n = int(input())
data = {}

for i in range(n):
  r = int(input())
  if r in data:
    data[r] += 1
  else:
    data[r] = 1

freqs = sorted(set(data.values()), reverse=True)
highest = sorted(filter(lambda k: data[k] == freqs[0], data.keys()))

if len(highest) > 1:
  print(abs(highest[0] - highest[-1]))
else:
  secondhighest = freqs[1]
  second = filter(lambda k: data[k] == secondhighest, data.keys())
  largest = max([abs(i-j) for j in second for i in highest])

  print (largest)