pieces = [int(i) for i in input().split(" ")]
normal = [1, 1, 2, 2, 2, 8]
need = []
if len(pieces) == 6:
    for i in range(6):
        need.append(normal[i] - pieces[i])
print(" ".join([str(i) for i in need]))
