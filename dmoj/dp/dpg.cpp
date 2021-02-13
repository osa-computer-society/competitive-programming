// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100005
using namespace std;

vector<int> adj[MAXN];
int dp[MAXN];

int dfs(int u)
{
    if (adj[u].size() == 0)
        return 0;
    if (dp[u] != -1)
        return dp[u];
    
    int ans = -0;
    for (int v : adj[u])
        ans = max(ans, dfs(v) + 1);
    
    return dp[u] = ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int N, M;
    cin >> N >> M;

    for (int i = 1, x, y; i <= M; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dfs(i));
    
    cout << ans << '\n';

    return 0;
}
