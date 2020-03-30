// Problem ID: ccc20p4
// By Alexander Cai
// Keywords: Prim's, Minimum Spanning Tree, Graph Theory

#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 105
#define MAXV 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;

pii vertex[MAXV][MAXV];
int c[10], w[10];
int adj[MAXN][MAXN], dis[MAXN];
bool vis[MAXN];

int mst(int N)
{
    for (int i = 1; i <= N; i++)
        dis[i] = INF, vis[i] = 0;
    dis[1] = 0;
    for (int cnt = 0; cnt < N-1; cnt++)
    {
        int u = -1, sm = INF;
        for (int v = 1; v <= N; v++)
            if (!vis[v] && dis[v] < sm)
                u = v, sm = dis[v];

        if (u == -1) return INF;
        vis[u] = 1;
        for (int v = 1; v <= N; v++)
            if (!vis[v] && adj[u][v] < INF)
                dis[v] = min(dis[v], adj[u][v]);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += dis[i];
    return ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < MAXV; i++)
        for (int j = 0; j < MAXV; j++)
            vertex[i][j] = make_pair(-1, -1);
    
    for (int i = 1; i <= N+1; i++)
        for (int j = 1; j <= N+1; j++)
            adj[i][j] = INF;

    for (int i = 1, e; i <= N; i++)
    {
        cin >> e;
        for (int j = 1; j <= e; j++) cin >> c[j];
        for (int j = 1; j <= e; j++) cin >> w[j];
        for (int j = 1; j <= e; j++)
        {
            int k = j%e + 1;
            pii &e = vertex[c[j]][c[k]], &f = vertex[c[k]][c[j]];
            if (e.second != -1)
            {
                if (adj[i][e.first] > w[j])
                    adj[i][e.first] = adj[e.first][i] = w[j];
                e.first = f.first = -1;
            }
            else
            {
                e.first = f.first = i;
                e.second = f.second = w[j];
            }
        }
    }

    for (int i = 1; i < MAXV; i++)
        for (int j = 1; j < MAXV; j++)
        {
            pii &e = vertex[i][j];
            if (e.first > 0 && adj[e.first][N+1] > e.second)
                adj[e.first][N+1] = adj[N+1][e.first] = e.second;
        }

    cout << min(mst(N), mst(N+1)) << '\n';

    return 0;
}
