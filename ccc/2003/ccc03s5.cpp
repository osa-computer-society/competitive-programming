// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 20005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> adj[MAXN];
int dis[MAXN], dest[MAXN];
bool in_mst[MAXN];
int N, M, D;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    int a, b, l;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> l;
        adj[a].push_back({b,l});
        adj[b].push_back({a,l});
    }
    for (int i = 0; i < D; i++) cin >> dest[i];

    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    for (int i = 0; i < N-1; i++)
    {
        int far = -1, u = 0;
        for (int j = 1; j <= N; j++)
            if (!in_mst[j] && dis[j] > far)
                far = dis[j], u = j;
        in_mst[u] = true;
        for (pii v : adj[u])
            if (!in_mst[v.first] && v.second > dis[v.first])
                dis[v.first] = v.second;
    }

    int ans = INF;
    for (int d = 0; d < D; d++)
        if (dis[dest[d]] < ans)
            ans = dis[dest[d]];
    cout << ans << '\n';

    return 0;
}
