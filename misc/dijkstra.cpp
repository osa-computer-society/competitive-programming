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

int dist[MAXV], N;
// We use a min-priority queue of integer pairs,
// where the first term is the distance from the starting vertex
// and the second term is the index of the vertex
priority_queue<pii, vector<pii>, greater<pii> > pq;
// The graph, stored as adjacency lists
vector<pii> adj[MAXV];

int main()
{
    // The number of vertices and the number of edges
    int V, E;
    cin >> V >> E;

    // Read the adjacency lists
    FOR(i, E)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    // run Dijkstra's starting from each individual vertex
    FOR(st, V)
    {
        memset(dist, 0x3f, sizeof dist);
        dist[st] = 0;
        pq.push(make_pair(0, st));
        while (!pq.empty())
        {
            // `u` is the closest node to the source node
            int u = pq.top().second; pq.pop();
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

    return 0;
}
