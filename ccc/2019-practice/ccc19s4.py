class Graph(object):
  def __init__(self):
    self.nodes = {}
    self.edges = []
  
  def addNode(self, pen):
    self.nodes.append(pen)
    self.vertices.extend(pen.corners)

class Pen(object):
  def __init__(self, _id, corners):
    self.id = _id
    self.corners = corners
    self.connections = set()

# graph = Graph()

edges = {}
nodes = [Pen(0, [])]

n = int(input())
for i in range(n):
  k = list(map(int, input().split()))
  e = k[0]
  corners, costs = (k[1:e+1], k[e+1:])

  nodes.append(Pen(i + 1, corners))

  for j in range(e): # Initialize a 2D array with the distances between any two vertices
    v1 = corners[j]
    v2 = corners[(j+1)%e]
    if v1 not in edges:
      edges[v1] = {}
    if v2 not in edges:
      edges[v2] = {}
    
    edges[v1][v2] = costs[j]
    edges[v2][v1] = costs[j]
  
    for l in range(len(nodes)):
      if l == i: continue
      if v1 in nodes[l].corners and v2 in nodes[l].corners:
        nodes[l].connections.add(i)
        nodes[i+1].connections.add(l)
  
print(edges)
for node in nodes:
  print(node.connections)