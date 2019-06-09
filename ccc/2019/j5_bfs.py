rules = [input().split() for i in range(3)]
md, i, f = input().split()
md = int(md)

class Node(object):
    def __init__(self, parent, r, ind, s):
        self.parent = parent
        self.children = []
        self.r = r
        self.ind = ind
        self.s = s

        for i in range(len(rules)): # For each of the rules
            toRep = rules[i][0]
            ind = s.find(toRep) # See if it applies to the string
            while ind >= 0: # While it does
                new = s[:ind] + rules[i][1] + s[ind + len(toRep):] # We create the r
                self.children.append(Node(self, i + 1, ind + 1, new))
                ind = s.find(toRep, ind + len(toRep)) # Otherwise we see if the rule appears again

class Tree(object):
    def __init__(self, md, ini, f):
        self.children = []
        for i in range(len(rules)): # For each of the rules
            toRep = rules[i][0]
            ind = ini.find(toRep) # See if it applies to the string
            while ind >= 0: # While it does
                new = ini[:ind] + rules[i][1] + ini[ind + len(toRep):] # We create the r
                self.children.append(Node(self, i + 1, ind + 1, new))
                ind = ini.find(toRep, ind + len(toRep)) # Otherwise we see if the rule appears again

def bfs(ps, depth):
    depth += 1
    if depth > md:
        for p in ps:
            if ps[i][2] == f:
                return ps[i]

    children = []
    for p in ps:
        for x in p.children:
            children.append(x)

    return bfs(children, depth)

Tree(md, i, f)