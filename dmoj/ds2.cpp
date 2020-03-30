// Problem ID: 
// By 
// Keywords: Kruskal's, Graph Theory, Connected Component, Disjoint Set

#include <iostream>
#include <vector>
#define MAXN 100005
using namespace std;

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

    int N, M, cnt = 0;
    vector<int> edges;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) par[i] = i, r[i] = 0;

    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (find_set(u) != find_set(v))
            cnt++, edges.push_back(i), link(find_set(u), find_set(v));
    }

    if (cnt != N-1) cout << "Disconnected Graph\n";
    else for (int e : edges) cout << e << '\n';

    return 0;
}
