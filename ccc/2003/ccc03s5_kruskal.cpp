// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef pair<int,int> pii;

struct edge
{
    int u, v, w;
    edge(int u, int v, int w): u(u), v(v), w(w) {}
};

bool operator <(edge const &a, edge const &b)
{
    return a.w < b.w;
}

int par[MAXN];
int r[MAXN];

int find_set(int u)
{
    if (par[u] != u) par[u] = find_set(par[u]);
    return par[u];
}

void link(int u, int v)
{
    if (r[u] > r[v]) par[v] = u;
    else
    {
        par[u] = v;
        if (r[u] == r[v]) r[v]++;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, D;
    vector<edge> E;
    int dest[D];
    cin >> N >> M >> D;

    for (int i = 1; i <= N; i++) par[i] = i, r[i] = 0;

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        E.push_back(edge(u, v, w));
    }
    sort(E.begin(), E.end());
    for (int i = 0; i < D; i++) cin >> dest[i];

    int cnt = 0;
    vector<edge> mst;
    while (cnt < N-1)
    {
        edge e = E.back(); E.pop_back();
        int u = find_set(e.u), v = find_set(e.v);
        if (u != v)
            cnt++, mst.push_back(e), link(u, v);
    }

    for (edge e : mst) cout << e.u << ' ' << e.v << ' ' << e.w << '\n';

    return 0;
}
