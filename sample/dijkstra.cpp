// dijkstra all-pairs shortest path

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
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> adj[MAXV];

int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    // run dDijkstra's starting from each individual vertex
    FOR(st, V)
    {
        memset(dist, 0x3f, sizeof dist);
        dist[st] = 0;
        pq.push(make_pair(0, st));
        while (!pq.empty())
        {
            int u = pq.top().second;
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

    return 0;
}
