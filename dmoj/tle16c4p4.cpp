// Problem ID: 
// By Alexander Cai

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int par[MAXN];
vector<pii> adj[MAXN];
ll diam, far, dist[MAXN];

void dfs(int u, int p)
{
    par[u] = p;
    if (dist[u] >= diam)
        diam = dist[u], far = u;
    for (pii e : adj[u])
        if (e.first != p)
            dist[e.first] = dist[u] + e.second, dfs(e.first, u);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    memset(par, -1, sizeof(par));

    int u, v, l;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    
    int tree = 0;
    vector<ll> rads, diams;
    for (int i = 1; i <= N; i++)
    {
        if (par[i] == -1)
        {
            tree++;
            dist[i] = 0, diam = 0;
            dfs(i, i);
            dist[far] = 0, diam = 0;
            dfs(far, far);
            ll rad = diam;
            for (int k = far; k != par[k]; k = par[k])
                rad = min(rad, max(diam-dist[k], dist[k]));
            rads.push_back(rad);
            diams.push_back(diam);
        }
    }

    if (Q == 1)
    {
        ll total = 0;
        for (ll d : diams) total += d;
        cout << total + tree - 1 << '\n';
    }
    else if (Q == 2)
    {
        ll max_r = 0, cnt = 0;
        for (ll r : rads)
        {
            if (r > max_r) max_r = r, cnt = 1;
            else if (r == max_r) cnt++;
        }
        cout << (cnt > 1 ? max_r + 1 : max_r) << '\n';
    }
}

