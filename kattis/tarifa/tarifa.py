x = int(input())
n = int(input())
total = x * (n + 1)
for i in range(n):
    total -= int(input())
print(total)
