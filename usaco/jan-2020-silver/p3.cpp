// Problem ID: 
// By 
// SOLVED!!!

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int par[MAXN];
int r[MAXN];
vector<pii> adj[MAXN];
int dis[MAXN], pos[MAXN];
bool in_mst[MAXN];
int N, M;

struct edge
{
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<edge> E;

bool operator <(edge const &a, edge const &b)
{
    return a.w < b.w;
}

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
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    fin >> N >> M;

    bool sorted = true;
    for (int i = 1; i <= N; i++)
        fin >> pos[i], par[i] = i, r[i] = 0, dis[i] = INF, sorted = sorted && (pos[i] == i);
    if (sorted)
    {
        fout << -1 << '\n';
        return 0;
    }

    int a, b, w;
    for (int i = 0; i < M; i++)
    {
        fin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        E.push_back(edge(a,b,w));
    }

    sort(E.begin(), E.end());

    // dis[1] = 0;
    // for (int i = 0; i < N-1; i++)
    // {
    //     int far = -1, u;
    //     for (int j = 1; j <= N; j++)
    //         if (!in_mst[j] && dis[j] > far)
    //             far = dis[j], u = j;
        
    //     in_mst[u] = true;
    //     for (pii v : adj[u])
    //         if (!in_mst[v.first] && v.second > dis[v.first])
    //             dis[v.first] = v.second;
    // }

    int cnt = 0;
    vector<edge> mst;
    while (cnt < N-1)
    {
        edge e = E.back(); E.pop_back();
        cout << "Adding edge " << e.u << ' ' << e.v << ' ' << e.w << '\n';

        if ((adj[e.u].size() == 1 && pos[e.u] == e.u) || (adj[e.v].size() == 1 && pos[e.v] == e.v))
        {
            cnt++;
            continue;
        }

        int u = find_set(e.u), v = find_set(e.v);
        if (u != v)
        {
            cnt++, mst.push_back(e), link(u, v);
            dis[e.u] = min(dis[e.u], e.w);
            dis[e.v] = min(dis[e.v], e.w);
            cout << "dis[" << e.u << "] " << dis[u] << '\n';
            cout << "dis[" << e.v << "] " << dis[v] << '\n';
        }
    }

    for (edge e : mst) cout << e.u << ' ' << e.v << ' ' << e.w << '\n';

    int ans = INF;
    for (int i = 1; i <= N; i++)
    {
        cout << i << ' ' << dis[i] << '\n';
        if (!(i == pos[i] && adj[i].size() == 1))
            ans = min(ans, dis[i]);
    }

    fout << ans << '\n';

    return 0;
}