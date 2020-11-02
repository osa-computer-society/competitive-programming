from math import sqrt

n, w, h = [int(x) for x in input().split(" ")]
largest = sqrt(w**2+h**2)
for i in range(n):
    if int(input()) <= largest:
        print("DA")
    else:
        print("NE")
