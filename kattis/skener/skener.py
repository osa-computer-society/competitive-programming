r, c, zr, zc = [int(x) for x in input().split(" ")]
result = []
for i in range(r):
    chars = list(input())
    if len(chars) == c:
        for i in range(len(chars)):
            chars[i] = chars[i] * zc
        for i in range(zr):
            result.append(chars)

for x in result:
    s = ""
    for y in x:
        s += y
    print(s)
