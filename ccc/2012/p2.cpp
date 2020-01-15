// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 20005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> adj[MAXN], adj_reverse[MAXN];
int dis[MAXN], dis_reverse[MAXN];
int N, M;

void dijkstra(int s, vector<pii> adj[], int dis[])
{
    priority_queue<int> Q;
    for (int i = 1; i <= N; i++)
        dis[i] = INF;
    dis[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.top(); Q.pop();
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
        adj[a].push_back({b,l});
        adj_reverse[b].push_back({a,l});
    }

    dijkstra(1, adj, dis);
    dijkstra(N, adj_reverse, dis_reverse);

    int ans = INF;
    for (int i = 1; i <= N; i++)
        for (pii e : adj[i])
        {
            int d = dis[i] + e.second + dis_reverse[e.first];
            if (d > dis[N]) ans = min(ans, d);
        }
    
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
