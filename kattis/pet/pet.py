scores = []
for i in range(5):
    scores.append(sum([int(x) for x in input().split(" ")]))

topscore = 0
for score in scores:
    if score > topscore:
        topscore = score
        index = scores.index(topscore) + 1

print(str(index) + " " + str(topscore))
