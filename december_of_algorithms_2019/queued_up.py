def queued_up(A, k):
    queue = []
    for pair in A:
        if pair[1] == k:
            queue.insert(0, pair)
        else:
            queue.append(pair)
    return queue
