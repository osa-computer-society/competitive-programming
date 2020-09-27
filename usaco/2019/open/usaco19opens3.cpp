// Problem ID: 
// By 

#include <iostream>
#include <vector>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;

int x[MAXN], y[MAXN], p[MAXN], r[MAXN], vis[MAXN];
vector<int> adj[MAXN];

int find_set(int u)
{
    if (p[u] != u) p[u] = find_set(p[u]);
    return p[u];
}

void link(int uu, int vv)
{
    int u = find_set(uu), v = find_set(vv);
    if (r[u] > r[v]) p[v] = u;
    else
    {
        p[u] = v;
        if (r[u] == r[v]) r[v]++;
    }
}

void dfs(int u, int &l, int &r, int &b, int &t)
{
    vis[u] = 1;
    l = min(l, x[u]), r = max(r, x[u]);
    b = min(b, y[u]), t = max(t, y[u]);
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, l, r, b, t);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> x[i] >> y[i], p[i] = i;

    for (int i = 1, a, b; i <= M; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        link(a, b);
    }

    int ans = INF;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i]) continue;
        int l = INF, r = -1, b = INF, t = -1;
        dfs(i, l, r, b, t);
        ans = min(ans, 2*(r-l + t-b));
    }

    cout << ans << '\n';

    return 0;
}
