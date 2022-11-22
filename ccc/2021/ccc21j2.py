n = int(input())
winner = ''
highestbid = -1
for i in range(n):
    name = input()
    bid = int(input())
    if bid > highestbid:
        winner = name
        highestbid = bid
print(winner)
