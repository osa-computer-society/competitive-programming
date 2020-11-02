cost = float(input())
lawns = int(input())
total = 0
for i in range(lawns):
    w, l = [float(x) for x in input().split(" ")]
    a = w * l
    total += a * cost
print(total)
