WHITE = 0
GRAY = 1
BLACK = 2

types = [None, 'G', 'H', 'GH']
str_to_int = { 'G': 0b01, 'H': 0b10 }

class node:
    def __init__(self, i, t, N):
        self.i = i
        self.type = t
        self.adj = []
        self.color = WHITE
        self.d = float('inf')
        self.p = None

    def __repr__(self):
        return f'<node i={self.i} p={self.p} d={self.d} type={self.type} adj={self.adj}>\n'

def path(a, b):
    m, n = a, b
    ans = []
    p1 = []
    p2 = []
    while a != b:
        if V[a].d < V[b].d:
            b = V[b].p
            p2.append(b)
        elif V[a].d > V[b].d:
            a = V[a].p
            p1.append(a)
        else:
            a = V[a].p
            b = V[b].p
            p1.append(a)
            p2.append(b)
    if len(p2) > 0: p2.pop()
    p2.reverse()
    return [m, *p1, *p2, n]

with open('milkvisits.in', 'r') as ifile:
    global V
    data = ifile.read().split('\n')
    N, M = map(int, data[0].split())
    V = [node(i, str_to_int[data[1][i]], N) for i in range(N)]
    for a, b in [map(int, line.split()) for line in data[2:N+1]]:
        V[a-1].adj.append(b-1)
        V[b-1].adj.append(a-1)
    
    V[0].color = GRAY
    V[0].d = 0
    Q = [0]
    while len(Q) > 0:
        u = Q.pop()
        for v in V[u].adj:
            if V[v].color == WHITE:
                V[v].color = GRAY
                V[v].d = V[u].d + 1
                V[v].p = u
                Q.append(v)
        V[u].color = BLACK
    
    with open('milkvisits.out', 'w') as ofile:
        for a, b, t in [line.split() for line in data[N+1:N+1+M]]:
            total = 0
            for j in path(int(a) - 1, int(b) - 1):
                total |= V[j].type
            ofile.write(str(int(t in types[total])))
