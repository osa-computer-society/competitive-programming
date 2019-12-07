def fibonacci(n):
    F = [1, 1]
    for i in range(n):
        F.append(F[i+1] + F[i])
    return F[2:]
