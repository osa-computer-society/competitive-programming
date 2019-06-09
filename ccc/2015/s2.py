j = int(input())
a = int(input())

sizes = {'S': 0, 'M': 1, 'L': 2}

jerseys = []
for i in range(j):
    jerseys.append(sizes[input()])

athletes = []
for i in range(a):
    temp = input().split()
    athletes.append((sizes[temp[0]], int(temp[1])-1))

for ath in athletes:
    if jerseys[ath[1]] >= ath[0]:
        jerseys[ath[1]] = -1

print(len(taken))