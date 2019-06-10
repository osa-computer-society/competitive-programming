k = int(input())
elapsed = 0
currPlayer = k
playerfound = -1
explosiontime = 3 * 60 + 30

for i in range(int(input())):
    t, z = input().split(" ")
    t = float(t)

    if elapsed < explosiontime and explosiontime <= elapsed + t:
        playerfound = currPlayer

    if z == "T":
        currPlayer += 1
    if currPlayer > 8:
        currPlayer %= 8
        

    elapsed += t
            
print(playerfound)
