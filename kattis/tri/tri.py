x = [int(n) for n in input().split(" ")]

if x[0] + x[1] == x[2]:
    o1 = "+"
    o2 = "="
elif x[1] + x[2] == x[0]:
    o1 = "="
    o2 = "+"
elif x[0] + x[2] == x[1]:
    o1 = "="
    o2 = "-"
elif x[0] * x[1] == x[2]:
    o1 = "*"
    o2 = "="
elif x[1] * x[2] == x[0]:
    o1 = "/"
    o2 = "="
elif x[0] * x[2] == x[1]:
    o1 = "="
    o2 = "/"

print(str(x[0]) + o1 + str(x[1]) + o2 + str(x[2]))
