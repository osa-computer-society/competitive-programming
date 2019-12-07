# import sys
# A = [x.split() for x in sys.stdin.read().split('\n') if x.strip() != '']

def cheeating_probability(A):
    R = len(A)
    C = len(A[0])
    N = [[.0 for __ in range(C)] for _ in range(R)]
    for r in range(R):
        for c in range(C):
            val = A[r][c]
            front = r > 0 and A[r-1][c] == val
            back = r < R-1 and A[r+1][c] == val
            left = c > 0 and A[r][c-1] == val
            right = c < C-1 and A[r][c+1] == val
            if front: N[r][c] += .3
            for d in (back, left, right):
                if d:
                    N[r][c] += .2
            tl = r > 0 and c > 0 and A[r-1][c-1] == val
            tr = r > 0 and c < C-1 and A[r-1][c+1] == val
            bl = r < R-1 and c > 0 and A[r+1][c-1] == val
            br = r < R-1 and c < C-1 and A[r+1][c+1] == val
            for d in (tl, tr, bl, br):
                if d:
                    N[r][c] += .1
    return N
