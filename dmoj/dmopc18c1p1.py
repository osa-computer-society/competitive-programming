import sys

data = sys.stdin.read().split('\n')

n = int(data[0])
A = [int(x) for x in data[1].split()]

def main():
    if n <= 2:
        print('YES')
        return

    low = -1
    high = float('inf')
    prev = -1
    for i in range(n):
        if A[i] == 0:
            if i > 0:
                low = max(low, A[i-1])
            if i < n-1:
                high = min(high, A[i+1])
        else:
            if prev > A[i]: 
                print('NO')
                return
            prev = A[i]

    print(('NO', 'YES')[low <= high])

main()
