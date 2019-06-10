n = int(input())
for i in range(n):
    g = int(input())
    cs = [int(x) for x in input().split(" ")]
    oddmanout = 0
    for c in cs:
        if cs.count(c) % 2 == 1:
            print("Case #" + str(i + 1) + ": " + str(c))
            break
