// solved 2020-09-22

// holy COW that took way too long
// Floyd-Warshall was too slow so I tried a dijkstra starting from each pasture

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXN 505
#define MAXP 805
using namespace std;
typedef pair<int, int> pii;
ifstream fin("butter.in");
ofstream fout("butter.out");

int pasture[MAXN], dist[MAXP], N;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> adj[MAXP];

int main()
{
    int P, C;
    fin >> N >> P >> C;
    for (int i = 1; i <= N; i++)
        fin >> pasture[i];
    for (int i = 1; i <= C; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    int ans = 0x3f3f3f3f;
    FOR(st, P)
    {
        memset(dist, 0x3f, sizeof dist);
        dist[st] = 0;
        pq.push(make_pair(0, st));
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            // if (dist[u.second] != u.first)
            //     continue;
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

        int tot = 0;
        FOR(i, N)
            tot += dist[pasture[i]];
        ans = min(ans, tot);
    }

    fout << ans << '\n';
}
