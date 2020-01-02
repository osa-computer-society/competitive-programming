# Solved

with open('gymnastics.in', 'r') as file:
    data = file.read().split('\n')
    K, N = map(int, data[0].split())
    adj = [[0 for _ in range(N)] for __ in range(N)]

    for row in [[int(x) for x in row.split()] for row in data[1:N+1]]:
        for i in range(N-1):
            for j in row[i+1:]:
                m = row[i] - 1
                n = j-1
                if adj[m][n] == 2:
                    continue
                if adj[n][m] == 1:
                    adj[m][n] = 2
                    adj[n][m] = 2
                else:
                    adj[m][n] = 1

    total = 0
    for line in adj:
        total += line.count(1)
    with open('gymnastics.out', 'w') as ofile:
        ofile.write(str(total))