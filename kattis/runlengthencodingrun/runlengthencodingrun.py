mode, inp = input().split()

ret = ""
if mode == "D":
    for i in range(len(inp) // 2):
        ret += inp[2*i] * int(inp[2*i+1])
elif mode == "E":
    prev = inp[0]
    cnt = 1
    for c in inp[1:]:
        if c != prev:
            ret += prev + str(cnt)
            prev = c
            cnt = 1
        else:
            cnt += 1
    ret += prev + str(cnt)

print(ret)
