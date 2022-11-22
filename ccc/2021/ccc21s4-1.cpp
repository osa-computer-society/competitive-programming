// Problem ID:
// By Alexander Cai

#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2005;
vector<int> adj[maxn];
int dist[maxn];
int train[maxn];

int N, W, D;

void relax(int u, int v)
{
    if (dist[v] > dist[u] + 1)
    {
        dist[v] = dist[u] + 1;
        for (int n : adj[v])
            relax(v, n);
        if (v == train[dist[v]] && dist[v] < N) // train is here
            relax(v, train[dist[v] + 1]);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W >> D;

    // walking trails
    int a, b;
    FOR(i, 1, W)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // train
    FOR(i, 1, N)
    cin >> train[i];

    int p, q;
    FOR(d, 1, D)
    {
        // swap positions
        cin >> p >> q;
        int tmp = train[p];
        train[p] = train[q];
        train[q] = tmp;

        memset(dist, 0x3f, sizeof(dist));
        dist[0] = 0;
        relax(0, 1);
        cout << dist[N] - 1 << '\n';
    }

    return 0;
}
