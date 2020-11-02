a = {}
score = 0
right = 0
while True:
    sub = input()
    if sub == '-1':
        break
    else:
        sub = sub.split(" ")
        if sub[2] == "wrong":
            try:
                a[sub[1]] += 20
            except KeyError:
                a[sub[1]] = 20
        elif sub[2] == "right":
            try:
                score += a[sub[1]] + int(sub[0])
            except KeyError:
                score += int(sub[0])
            right += 1

print(str(right) + " " + str(score))

