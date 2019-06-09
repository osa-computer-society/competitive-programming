# CCC 2016 Senior 3
# Solution by Emmanuel Mathi-Amorim
 
#---------------------------------------------------------------------------
# Node Graph
#---------------------------------------------------------------------------
 
class Node:
    def __init__(self, id):
        self.id = id
        self.isPhoRestaurant = False
        self.connections = []

phoRestaurants = []
 
def initGraph():
    global nodes
    nodes = []
    for i in range(numberOfRestaurants):
        nodes.append(Node(i))

 
def addPhoRestaurant(pho):
    global phoRestaurants
    phoRestaurants.append(pho)
    nodes[pho].isPhoRestaurant = True

 
def addConnection(a, b):
    nodes[a].connections.append(b)
    nodes[b].connections.append(a)

 
#---------------------------------------------------------------------------
# Input
#---------------------------------------------------------------------------
 
def readInput():
    global numberOfRestaurants, numberOfPhoRestaurants
    numberOfRestaurants, numberOfPhoRestaurants = map(int, input().split())
    initGraph()
    [addPhoRestaurant(int(x)) for x in input().split()]

    for i in range((numberOfRestaurants - 1)):
        x, y = map(int, input().split())
        addConnection(x, y)

 
#---------------------------------------------------------------------------
# Get Farthest Pho Restaurant
#---------------------------------------------------------------------------
 
def depthFirstSearch(startingNode, previousNode, distanceToStartingNode, result):
    for i in range(len(nodes[startingNode].connections)):
        currentNode = nodes[startingNode].connections[i]
        if (currentNode != previousNode):
            distanceToCurrentNode = distanceToStartingNode + 1
            if (distanceToCurrentNode > result['maxDistance'] and nodes[currentNode].isPhoRestaurant):
                result['maxDistance'] = distanceToCurrentNode
                result['maxDistanceNode'] = currentNode
            depthFirstSearch(currentNode, startingNode, distanceToCurrentNode, result)

 
def getFarthestPhoRestaurant(startingNode, result):
    depthFirstSearch(startingNode, startingNode, 0, result)

 
#---------------------------------------------------------------------------
# Solvers
#---------------------------------------------------------------------------
 
def solveAllDoesSubtreeContainPhoRestaurant(startingNode, previousNode):
    node = nodes[startingNode]
    if node.isPhoRestaurant:
        doesSubtreeContainPhoRestaurant[startingNode] = True
    for i in range(len(node.connections)):
        currentNode = node.connections[i]
        if (currentNode != previousNode):
            solveAllDoesSubtreeContainPhoRestaurant(currentNode, startingNode)
            if doesSubtreeContainPhoRestaurant[currentNode]:
                doesSubtreeContainPhoRestaurant[startingNode] = True

 
def solveSubtree(startingNode, previousNode, cost):
    node = nodes[startingNode]
    for i in range(len(node.connections)):
        currentNode = node.connections[i]
        if (currentNode != previousNode):
            if (doesSubtreeContainPhoRestaurant[currentNode]):
                cost['cost'] += 2
                solveSubtree(currentNode, startingNode, cost)

 
def solveTree(startingNode):
    global doesSubtreeContainPhoRestaurant
    doesSubtreeContainPhoRestaurant = [False] * numberOfRestaurants
    solveAllDoesSubtreeContainPhoRestaurant(startingNode, startingNode)
    cost = {'cost': 0}
    solveSubtree(startingNode, startingNode, cost)
    del doesSubtreeContainPhoRestaurant
    return cost['cost']

 
#---------------------------------------------------------------------------
# Main
#---------------------------------------------------------------------------
 
def main():
    readInput()
    maxDistance = 0
    optimalStartingNode = 0
    optimalEndingNode = 0

    result = {'maxDistanceNode': optimalStartingNode, 'maxDistance': maxDistance}
    getFarthestPhoRestaurant(phoRestaurants[0], result)
    cost = solveTree(optimalStartingNode)

    result = {'maxDistanceNode': optimalEndingNode, 'maxDistance': result['maxDistance']}
    getFarthestPhoRestaurant(optimalStartingNode, result)
    finalCost = cost - result['maxDistance']
    print(finalCost)

main()
