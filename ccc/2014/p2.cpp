// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct edge
{
    int u, v, l, c;
    edge(int u, int v, int l, int c): u(u), v(v), l(l), c(c) {}
};

vector<pii> adj[MAXN], radj[MAXN];
vector<edge> E;
int dis[MAXN], rdis[MAXN], psa[MAXN];
int N, M, A, B;

void dijkstra(int s, int dis[], vector<pii> adj[])
{
    priority_queue<pii> Q;
    for (int i = 1; i <= N; i++)
        dis[i] = INF;
    dis[s] = 0;
    Q.push({0,s});
    while (!Q.empty())
    {
        int d = Q.top().first, u = Q.top().second; Q.pop();
        if (dis[u] < d) continue;
        for (pii e : adj[u])
            if (dis[u] + e.first < dis[e.second])
                dis[e.second] = dis[u] + e.first, Q.push({dis[e.second],e.second});
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> A >> B;

    int a, b, l, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> l >> c;
        adj[a].push_back({l,b});
        radj[b].push_back({l,a});
        E.push_back(edge(a,b,l,c));
    }

    dijkstra(A, dis, adj);
    dijkstra(B, rdis, radj);

    vector<pii> roads;
    for (edge e : E)
        if (dis[e.u] < INF && rdis[e.v] < INF)
            roads.push_back({dis[e.u] + e.l + rdis[e.v], e.c});
    sort(roads.begin(), roads.end());

    int total = 0;
    for (int i = 0; i < roads.size(); i++)
        total += roads[i].second, psa[i+1] = total;

    int Q, d;
    cin >> Q;
    while (Q--)
    {
        cin >> d;
        auto it = upper_bound(roads.begin(), roads.end(), make_pair(d, INF));
        cout << psa[it-roads.begin()] << '\n';
    }

    return 0;
}
