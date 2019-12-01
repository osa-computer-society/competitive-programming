def max_heapify(A, i):
    l = i << 1
    r = i << 1 + 1
    largest = l if (l < len(A) and A[l] > A[i]) else i
    if r < len(A) and A[r] > A[i]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        max_heapify(A, largest)

A = [5, 4, 7, 1, 5, 2]
print(max_heapify(A))
