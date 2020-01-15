// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct edge
{
    int u, v, l;
    edge(int u, int v, int l) : u(u), v(v), l(l) {}
};

vector<edge> E;
vector<pii> adj[MAXN];
int dis[MAXN];
int N, M;

void dijkstra(int s)
{
    for (int i = 1; i <= N; i++)
        dis[i] = INF;
    dis[s] = 0;
    priority_queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.top(); Q.pop();
        for (pii e : adj[u])
            if (dis[u] + e.second < dis[e.first])
                dis[e.first] = dis[u] + e.second, Q.push(e.first);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int a, b, l;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> l;
        E.push_back(edge(a, b, l));
    }

    int A, B, C;
    cin >> A >> B >> C;

    for (int i = 0; i < M; i++)
    {
        edge e = E[i];
        adj[e.u].push_back({e.v,e.l});
        adj[e.v].push_back({e.u,e.l});
        dijkstra(A);
        if (dis[B] < C)
        {
            cout << i+1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}
