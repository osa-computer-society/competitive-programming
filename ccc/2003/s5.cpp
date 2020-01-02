// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <limits>
#define MAXN 10000
using namespace std;
typedef pair<int,int> pii;

const int INF = numeric_limits<int>::max();

int adj[MAXN+1][MAXN+1];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, D;
    cin >> N >> M >> D;

    int dests[D];
    int x, y, w;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        if (w > adj[x][y]) adj[x][y] = w, adj[y][x] = w;
    }

    for (int i = 0; i < D; i++) cin >> dests[i];

    int val[N+5];
    bool vis[N+5];
    memset(val, 0, sizeof(val));
    memset(vis, 0, sizeof(vis));
    val[1] = INF;
    int mt = 1, largest, u;
    do
    {
        u = mt;
        vis[u] = 1;
        largest = 0;
        mt = -1;
        for (int v = 1; v <= N; v++)
        {
            val[v] = max(val[v], min(val[u], adj[u][v]));
            if (val[v] >= largest && !vis[v])
                largest = val[v], mt = v;
        }
    } while (mt != -1);
    
    int smallest = INF;
    for (int i = 0; i < D; i++)
        smallest = min(smallest, val[dests[i]]);
    
    cout << smallest << '\n';

    return 0;
}
