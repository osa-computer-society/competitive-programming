def is_sorted(A):
    for i in range(1, len(A)):
        if A[i] < A[i-1]:
            return False
    return True

def decimate(A):
    while not is_sorted(A):
        A = A[::2]
    return A