// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 20
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<pii> adj[MAXN];
int N, dp[MAXN][1<<MAXN];

int dfs(int u, int mask)
{
    if (u == N-1)
        return 0;
    if (dp[u][mask] != -1)
        return dp[u][mask];
    
    int ans = -0x3f3f3f3f;
    for (pii v : adj[u])
        if (!(mask & (1<<v.first)))
            ans = max(ans, dfs(v.first, mask|(1<<v.first)) + v.second);
    
    return dp[u][mask] = ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int M;
    cin >> N >> M;

    for (int i = 1, x, y, w; i <= M; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
    }
    
    cout << dfs(0, 1) << '\n';

    return 0;
}
