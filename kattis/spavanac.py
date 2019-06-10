h, m = [int(x) for x in input().split(" ")]
t = (h * 60 + m - 45)
if t < 0: t = t + 24 * 60
print(str(t // 60) + " " + str(t % 60))
