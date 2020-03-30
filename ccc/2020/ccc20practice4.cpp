// Problem ID: ccc20practice4.cpp
// By 

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 105
using namespace std;
typedef pair<int,int> pii;

int N;

struct edge
{
    int u, v, l;
    edge(int u, int v, int l): u(u), v(v), l(l) {}
};

int vertex[1005][1005], cost[1005][1005];
int c[10], w[10];

int par[MAXN];
int find_set(int u)
{
    if (u != par[u]) par[u] = find_set(par[u]);
    return par[u];
}

int rk[MAXN];
void link(int uu, int vv)
{
    int u = find_set(uu), v = find_set(vv);
    if (rk[u] < rk[v]) par[u] = v;
    else
    {
        par[v] = u;
        if (rk[u] == rk[v]) rk[u]++;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(vertex, -1, sizeof(vertex));

    cin >> N;

    vector<edge> E;

    int nvertices = -1;
    for (int i = 1, e; i <= N; i++)
    {
        par[i] = i, rk[i] = 0;
        cin >> e;
        for (int j = 1; j <= e; j++) cin >> c[j], nvertices = max(nvertices, c[j]);
        for (int j = 1; j <= e; j++) cin >> w[j];
        for (int j = 1; j < e; j++)
        {
            int k = vertex[c[j+1]][c[j]];
            if (k != -1)
            {
                E.push_back(edge(i, k, w[j]));
                vertex[c[j+1]][c[j]] = vertex[c[j]][c[j+1]] = -1;
            }
            else
            {
                vertex[c[j+1]][c[j]] = vertex[c[j]][c[j+1]] = i;
                cost[c[j]][c[j+1]] = cost[c[j+1]][c[j]] = w[j];
            }
        }
        int k = vertex[c[e]][c[1]];
        if (k != -1)
        {
            E.push_back(edge(i, k, w[e]));
            vertex[c[e]][c[1]] = vertex[c[1]][c[e]] = -1;
        }
        else
        {
            vertex[c[e]][c[1]] = vertex[c[1]][c[e]] = i;
            cost[c[e]][c[1]] = cost[c[1]][c[e]] = w[e];
        }
    }

    auto cmp = [](edge &a, edge &b){ return a.l > b.l; };
    sort(E.begin(), E.end(), cmp);
    int ans1 = 0;
    for (edge e : E)
    {
        if (find_set(e.u) == find_set(e.v)) continue;
        link(e.u, e.v);
        ans1 += e.l;
    }

    for (int i = 1; i <= nvertices; i++)
        for (int j = i; j <= nvertices; j++)
        {
            int k = vertex[i][j];
            if (k != -1)
                E.push_back(edge(N+1, k, cost[i][j]));
        }

    sort(E.begin(), E.end(), cmp);

    for (int i = 1; i <= N+1; i++) par[i] = i, rk[i] = 0;
    int ans2 = 0;
    for (edge e : E)
    {
        if (find_set(e.u) == find_set(e.v)) continue;
        link(e.u, e.v);
        ans2 += e.l;
    }

    cout << min(ans1, ans2) << '\n';

    return 0;
}
