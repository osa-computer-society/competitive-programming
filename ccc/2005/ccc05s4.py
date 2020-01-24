# NOT FINISHED

import sys
input = sys.stdin.readline

l = int(input())
for _ in range(l):
    n = int(input())
    names = [input() for __ in range(n)]

    height = 0
    max_height = 0
    s = [names[-1]]
    for name in names:
        try:
            i = s.index(name)
            height = i
            s = s[:i+1]
            max_height = max(height, max_height)
        except ValueError:
            s.append(name)
            height = len(s)-1
            max_height = max(height, max_height)
    print(n * 10 - 2 * max_height * 10)
