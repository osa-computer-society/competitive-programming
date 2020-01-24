class Page:
    def __init__(self, val, children):
        self.val = val
        self.children = children
    
    def isLeaf(self):
        return len(self.children) == 0

def getReachable(page, arr):
    for p in page.children:
        if p not in arr:
            arr.append(p)
            getReachable(pages[p], arr)

def bfs(ps, depth):
    depth += 1
    children = []
    for p in ps:
        if p.isLeaf():
            return depth
        else:
            for q in p.children:
                children.append(pages[q])
    return bfs(children, depth)

n = int(input())
pages = {}
for i in range(1, n+1):
    inpt = list(map(int, input().split()))
    if inpt[0] == 0:
        pages[i] = Page(i, [])
    else:
        pages[i] = Page(i, inpt[1:])

reachable = [1]
getReachable(pages[1], reachable)

if len(reachable) != n:
    print('N')
else:
    print('Y')

print(bfs([pages[1]], 0))
