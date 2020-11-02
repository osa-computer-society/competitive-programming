n, p, k = map(int, input().split())
ts = [int(x) for x in input().split()]

tot = 0
prev = 0
for i in range(n):
    tot += (ts[i] - prev) * (100 + i * p) / 100
    prev = ts[i]

tot += (k - prev) * (100 + n * p) / 100

print(tot)
