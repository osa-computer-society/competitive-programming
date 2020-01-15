// Problem ID: 
// By 

#include <iostream>
#include <queue>
#include <vector>
#define MAXN 1005
using namespace std;

struct edge
{
    int u, v, l;
    edge(int u, int v, int l): u(u), v(v), l(l) {}
};

int par[MAXN], r[MAXN];

int find_set(int u)
{
    if (u != par[u]) par[u] = find_set(par[u]);
    return par[u];
}

void link(int u, int v)
{
    u = find_set(u), v = find_set(v);
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
    
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        par[i] = i;

    auto compare = [](edge a, edge b) { return a.l > b.l; };

    priority_queue<edge, vector<edge>, decltype(compare)> Q(compare);

    for (int i = 0, a, b, l; i < M; i++)
    {
        cin >> a >> b >> l;
        Q.push(edge(a, b, l));
    }

    int n_edges = 0;
    vector<edge> mst;
    while (n_edges < N-1)
    {
        edge e = Q.top(); Q.pop();
        if (find_set(e.u) == find_set(e.v)) continue;
        n_edges++;
        link(e.u, e.v);
        mst.push_back(e);
    }

    for (edge e : mst) cout << e.u << ' ' << e.v << ' ' << e.l << '\n';
    
    return 0;
}
