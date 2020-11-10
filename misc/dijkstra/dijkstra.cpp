// Using Dijkstra's to calculate all-pairs shortest paths

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXV 805
using namespace std;
typedef pair<int, int> pii;

// dist[k] is the distance to vertex k
int dist[MAXV], N;

// The graph, stored as adjacency lists
vector<pii> adj[MAXV];

// s - the source vertex
void dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    // We use a min-priority queue of integer pairs,
    // where the first term is the distance from the starting vertex
    // and the second term is the index of the vertex
    // i.e. top element is the closest to origin
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        int u = pq.top().second; // the closest node
        pq.pop();
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int w = adj[u][i].first, v = adj[u][i].second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    // The number of vertices and the number of edges
    int V, E, s;
    cin >> V >> E >> s;

    // Read the adjacency lists
    FOR(i, E)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    // run Dijkstra's starting from each individual vertex
    FOR(s, V)
    {
        dijkstra(s);
    }

    return 0;
}
