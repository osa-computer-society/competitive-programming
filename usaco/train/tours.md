# 3.1 Eulerian tours

- **Eulerian tour:** a path which traverses each edge of a graph exactly once
  - Exists iff connected graph and all but two vertices have even degree
  - These two vertices are start and end points
- **Eulerian circuit:** an Eulerian tour that starts and ends at the same vertex
  - Exists iff connected and every vertex has even degree

## The algorithm

### Finding a circuit

General idea:

1. Start at a node
2. Determine a circuit leading back to that node
3. As we add edges:
   - For each node along the path:
      - If it has edges that haven't been visited:
        - Find a new circuit starting from that node and later attach it to the main circuit
4. Loop this until the edges of every node in the original circuit have been visited

```cpp
vector<int> circuit;
int adj[MAXN][MAXN]; // graph stored as adjacency matrix

// finds a circuit starting at node `u`
void find_circuit(int u)
{
  // while u has neighbors
  for (int v = 1; v <= V; ++v)
    // if an edge exists
    if (adj[u][v] != -1)
    {
      // take a random neighbor, remove the connection, and recursively find a circuit starting there
      adj[u][v] = adj[v][u] = -1;
      find_circuit(v);
    }
  circuit.push(u);
}
```

To find an Eulerian tour, find one of the two nodes with odd degree and call `find_circuit()` on it.

Time: $O(|V| + |E|)$

This also works if there are self-loops and multiple edges between vertices. Finding a Eulerian path in a directed graph is harder:

> A directed graph has a Eulerian circuit if it is strongly connected (except for nodes with both in-degree and out-degree of 0) and the indegree of each node equals its outdegree. The algorithm is exactly the same, except that because of the way this code finds the cycle, you must traverse arcs in reverse order.
