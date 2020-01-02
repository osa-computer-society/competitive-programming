A, B, X = map(int, input().split())
total = B // X - A // X
if A % X == 0: total += 1
print(total)