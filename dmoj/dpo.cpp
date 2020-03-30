// Problem ID: 
// By 
// Keywords: Dynamic Programming

#include <iostream>
#include <cstring>
#define MAXN 22
using namespace std;
typedef long long ll;

int dp[MAXN][1<<MAXN];
bool adj[MAXN][MAXN];
int N;

int recurse(int i, ll mask)
{
    if (mask+1 == 1<<N) return 1;
    if (i > N) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];
    
    ll ans = 0;
    for (int j = N; j >= 1; j--)
        if (!(mask & (1<<(j-1))) && adj[i][j])
            ans += recurse(i+1, mask|(1<<(j-1)));
    return dp[i][mask] = ans%((ll)1e9+7);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> adj[i][j];
    
    cout << recurse(1, 0) << '\n';

    return 0;
}
