total = 0
graph = { c: ((ord(c) - ord('A')) // 4, (ord(c) - ord('A')) % 4) for c in 'ABCDEFGHIJKLMNO'}
for i in range(4):
    n = input()
    for j in range(4):
        if n[j] == '.': continue
        x, y = graph[n[j]]
        total += abs(i-x) + abs(j-y)
print(total)
