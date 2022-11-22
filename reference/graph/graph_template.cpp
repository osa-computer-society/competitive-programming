// Problem ID:
// By

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 20005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[MAXN];
int dis[MAXN];
int N, M;

void dijkstra(int s)
{
    priority_queue<int> Q;
    for (int i = 1; i <= N; i++)
        dis[i] = INF;
    dis[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        for (pii e : adj[u])
            if (dis[u] + e.second < dis[e.first])
                dis[e.first] = dis[u] + e.second, Q.push(e.first);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int a, b, l;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }

    return 0;
}
