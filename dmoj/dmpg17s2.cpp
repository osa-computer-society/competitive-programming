// Problem ID: 
// By 

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

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) par[i] = i, r[i] = 0;

    char q;
    int u, v;
    for (int i = 1; i <= Q; i++)
    {
        cin >> q >> u >> v;
        if (q == 'A' && find_set(u) != find_set(v))
            link(find_set(u), find_set(v));
        else if (q == 'Q') cout << (find_set(u) == find_set(v) ? 'Y' : 'N') << '\n';
    }

    return 0;
}
