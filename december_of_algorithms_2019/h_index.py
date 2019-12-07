def h_index(n, A):
    i = 0
    while True:
        if len([x for x in A if x > i]) <= i:
            return i
        i += 1
