# Alexander Cai 2021-02-17

n = int(input())
h = [int(x) for x in input().split()]
w = [int(x) for x in input().split()]

total = 0
for i in range(n):
    total += (h[i] + h[i+1]) * w[i] / 2

print(total)
