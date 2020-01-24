# Get input
N, M = map(int, input().split()) # N - the number of restaurants, M - the number of pho restaurants
pho = list(map(int, input().split())) # A list of the pho restaurants

phos = [False for x in range(N)]
leaves = [True for x in range(N)]
paths = [[] for x in range(N)]
nodes = [False for x in range(N)]

total = 0 # The total of the tree
ind = [x for x in range(N)]
dists = [1 for x in range(N)]
maxdist = 0 # The longest distance in the tree

def mark(curr, prev): # goes through each of the nodes recursively, setting it to true if it is a pho restaurant
  if phos[curr] and not nodes[curr]: # If the current node is a pho restaurant
    nodes[curr] = True # The current node is included in the subtree
    global total
    total += 2

  for i in paths[curr]: # For all of the connections of this node
    if i != prev: # If it was not the previous one
      mark(i, curr) # We go through the connections of that node as well
      if nodes[i] and not nodes[curr]: # If it is a pho restaurant and the current one is not
        nodes[curr] = True # This one must also be included in the subtree
        global total
        total += 2

def depthFirstSearch(curr, prev, dist):
  for i in paths[curr]:
    if i != prev and nodes[i]:
      depthFirstSearch(i, curr, dist+1)
      if dists[i]+1 > dists[curr]:
        dists[curr] = dists[i]+1
        ind[curr] = ind[i]

def depthFirstSearch2(curr, prev, dist):
  global maxdist
  if dist > maxdist:
    maxdist = dist
  for i in paths[curr]:
    if i != prev and nodes[i]:
      depthFirstSearch2(i, curr, dist+1)

for i in range(M):
  phos[pho[i]] = True

for i in range(N-1):
  a, b = map(int, input().split())
  paths[a].append(b)
  paths[b].append(a)

mark(pho[0], -1)
depthFirstSearch(pho[0], -1, 0)
depthFirstSearch2(ind[pho[0]], -1, 0)
total -= 2
print(total - maxdist)
