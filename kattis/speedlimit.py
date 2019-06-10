while True:
    i = int(input())
    if i == -1:
        exit()
    else:
        mph = []
        time = []
        for x in range(i):
            pair = [int(x) for x in input().split(" ")]
            mph.append(pair[0])
            if x == 0:
                time.append(pair[1])
            else:
                t = pair[1]
                for n in time:
                    t -= n
                time.append(t)
        miles = 0
        for i in range(len(mph)):
            miles += mph[i] * time[i]
        print(str(miles) + " miles")
            
