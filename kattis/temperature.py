x, y = [int(x) for x in input().split(" ")]

if x == 0 and y==1:
    print("ALL GOOd")
elif y == 1:
    print("IMPOSSIBLE")
else:
    print(-x/(y-1))
