t = int(input())
for i in range(t):
    r, c = [int(x) for x in input().split(" ")]
    pic = []
    for j in range(r):
        pic.append(input())
    for x in range(len(pic)):
        pic[x] = pic[x][::-1]
    pic = pic[::-1]
    
    print("Test " + str(i+1))
    for y in pic:
        print(y)
        
