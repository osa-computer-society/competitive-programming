while True:
    i1, i2 = [int(x) for x in input().split(" ")]
    if (i1, i2) == (0, 0):
        break
    print(str(i1 // i2) + " " + str(i1 % i2) + " / " + str(i2))
    
