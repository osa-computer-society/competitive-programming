# Problem ID: 120
# By Alexander Cai 2019-11-26

import sys

for line in [[int(x) for x in l.strip().split()] for l in sys.stdin]:
    A = sorted(line)
    n = len(A)
    print(' '.join(map(str, line)))
    for i in range(len(A)):
        # the index it should be in
        k = n - i - 1
        key = A[k]
        j = line.index(key)
        if j != k:
            if j != 0:
                print(n-j, end=' ')
                line = line[:j+1][::-1] + line[j+1:]
            print(n-k, end=' ')
            line = line[:k+1][::-1] + line[k+1:]
    print(0)
