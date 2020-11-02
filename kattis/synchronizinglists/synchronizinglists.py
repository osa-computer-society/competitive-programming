while True:
    n = int(input())
    if n == 0: break
    l1, l2 = ([], [])
    syncedlist = [None] * n
    
    for i in range(n):
        l1.append(int(input()))
    for i in range(n):
        l2.append(int(input()))
        
    l1sorted = sorted(l1)
    l2sorted = sorted(l2)
    
    for i in range(len(l1sorted)):
        ind = l1.index(l1sorted[i])
        syncedlist[ind] = l2sorted[i]
    
    for num in syncedlist:
        print(num)
    print()
