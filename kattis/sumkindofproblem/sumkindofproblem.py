p = int(input())
for dset in range(p):
    k, n = [int(x) for x in input().split(" ")]
        
    print(str(k) + " " + str(n * (n+1) // 2) + " " + str(n**2) + " " + str(n**2+n))
