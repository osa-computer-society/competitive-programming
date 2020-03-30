// Problem ID: rte16s3
// By Alexander Cai
// Solved 5 Jan 2020
// Keywords: Sparse Table, Lowest Common Ancestor, Binary Lifting

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#define MAXN 6005
using namespace std;
typedef pair<int,int> pii;

vector<pii> adj[MAXN];
int st[MAXN][MAXN];
long long depth[MAXN], dist[MAXN], max_d = -1, l;

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v); // u is farther
    for (int k = l; k >= 0; k--)
        if (st[k][u] != -1 && depth[st[k][u]] >= depth[v])
            u = st[k][u];
    if (u == v) return v;
    for (int k = l; k >= 0; k--)
        if (st[k][u] != -1 && st[k][v] != -1 && st[k][u] != st[k][v])
            u = st[k][u], v = st[k][v];
    return st[0][u];
}

void dfs(int u, int p)
{
    st[0][u] = p;
    max_d = max(max_d, depth[u]);
    for (pii v : adj[u])
        if (v.first != p)
            depth[v.first] = depth[u] + 1, dist[v.first] = dist[u]+v.second, dfs(v.first, u);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, Q, a, b, w;
    cin >> N;
    
    for (int i = 0; i < N-1; i++)
    {
        for (int k = 0; k < log2(N); k++)
            st[k][i] = -1;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    depth[0] = 0, dist[0] = 0;
    dfs(0, -1);
    l = ceil(log2(max_d));

    for (int k = 1; k <= l; k++)
        for (int i = 0; i < N; i++)
            if (st[k-1][i] != -1)
                st[k][i] = st[k-1][st[k-1][i]];

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        cout << dist[a] + dist[b] - dist[lca(a, b)] * 2 << '\n';
    }

    return 0;
}
