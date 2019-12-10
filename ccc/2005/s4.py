# NOT FINISHED

import sys
input = sys.stdin.readline

l = int(input())
for i in range(l):
    n = int(input())
    names = [input() for __ in range(n)]

    ans = -1
    s = [names[-1]]
    for j in names:
        if len(s) > 1 and j == s[-2]:
            s.pop()
        else:
            s.append(j)
            if len(s) > ans:
                ans = len(s)
    print(10 * (n-ans+1) - 20)
