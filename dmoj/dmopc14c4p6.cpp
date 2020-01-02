// Problem ID: 
// By Alexander Cai

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#define MAXN 500000
using namespace std;

const int INF = numeric_limits<int>::max();

int down_dp[MAXN];
int up_dp[MAXN];
int vis[MAXN];
int par[MAXN];
vector<int> adj[MAXN];

int down(int u)
{
    if (down_dp[u] >= 0) return down_dp[u];
    int max = 0;
    for (int i : adj[u])
        if (i != par[u] && down(i) + 1 > max)
            max = down_dp[i] + 1;
    return down_dp[u] = max;
}

int up(int u)
{
    if (par[u] < 0) return 0;
    if (up_dp[u] >= 0) return up_dp[u];
    int max = up(par[u]) + 1;
    for (int i : adj[par[u]])
        if (i != u && i != par[par[u]] && down(i) + 2 > max)
            max = down_dp[i] + 2;
    return up_dp[u] = max;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, a, b;
    cin >> N;

    for (int i = 0; i < N; i++) down_dp[i] = up_dp[i] = -1;

    for (int i = 0; i < N-1; i++)
    {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    queue<int> Q;
    vis[0] = 1;
    par[0] = -1;
    Q.push(0);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for (int i : adj[u])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                par[i] = u;
                Q.push(i);
            }
        }
    }

    for (int i = 0; i < N; i++) cout << max(up(i), down(i)) + 1 << "\n";

    return 0;
}
