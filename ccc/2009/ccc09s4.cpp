#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 5005
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int adj[MAXN][MAXN], cost[MAXN];
bool vis[MAXN];
ll dis[MAXN];

void dijkstra(int N, int D)
{
    for (int i = 1; i <= N; i++)
        dis[i] = INF;
    dis[D] = 0;
    int cnt = 0;
    while (cnt < N)
    {
        int small = INF, u = 0;
        for (int i = 1; i <= N; i++)
            if (!vis[i] && dis[i] < small)
                small = dis[i], u = i;
        vis[u] = true;
        cnt++;
        for (int v = 1; v <= N; v++)
            if (adj[u][v] && dis[u] + adj[u][v] < dis[v])
                dis[v] = dis[u] + adj[u][v];
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(cost, -1, sizeof(cost));

    int N, M;
    scan(N);
    scan(M);
    for (int i = 1, u, v, w; i <= M; i++)
    {
        scan(u); scan(v); scan(w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
    int K;
    scan(K);
    for (int i = 1, z, p; i <= K; i++)
    {
        scan(z); scan(p);
        cost[z] = p;
    }
    int D;
    scan(D);

    // END INPUT

    dijkstra(N, D);

    ll ans = INF;
    for (int i = 1; i <= N; i++)
        if (cost[i] >= 0)
            ans = min(ans, cost[i] + dis[i]);
    
    if (ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
