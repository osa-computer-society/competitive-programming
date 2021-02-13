names = ['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
adj = {name: list() for name in names}
done = {name: False for name in names}
lines = []

def add(n):
    if done[name]:
        return

    if len(adj[n]) == 2:
        stack = [n]
        done[n] = True
        for i in (0, 1):
            prev = n
            k = adj[n][i]
            while True:
                done[k] = True
                if i == 0: stack.insert(0, k)
                else: stack.append(k)
                if len(adj[k]) == 1:
                    break
                # now it is attached to the next one
                adj[k].remove(prev)
                prev, k = k, adj[k][0]
        
        if stack[-1] < stack[0]:
            stack = stack[::-1]
            
        lines.append(stack)

    elif len(adj[n]) == 1:
        if len(adj[adj[n][0]]) == 2:
            add(adj[n][0])
        else:
            done[n] = True
            done[adj[n][0]] = True
            lines.append([min(adj[n][0], n), max(adj[n][0], n)])
        
    else:
        lines.append([n])
        done[n] = True

with open('lineup.in', 'r') as ifile:
    data = ifile.read().split('\n')
    for a, b in [_.split(' must be milked beside ') for _ in data[1:1+int(data[0])]]:
        adj[a].append(b)
        adj[b].append(a)

    for name in names:
        add(name)
    lines = sorted(lines, key=lambda x: x[0])
    
    with open('lineup.out', 'w') as ofile:
        ofile.write('\n'.join([item for sl in lines for item in sl]))