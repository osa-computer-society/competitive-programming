// Problem Name: Slimes
// By Alexander Cai
// Keywords: Dynamic Programming

#include <iostream>
#include <cstring>
#define MAXN 405
using namespace std;
typedef long long ll;

ll psa[MAXN], dp[MAXN][MAXN];

ll solve(int i, int j)
{
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll n = 9*1e18;
    for (int k = i; k < j; k++)
        n = min(n, solve(i, k) + solve(k+1, j));
    return dp[i][j] = n + psa[j] - psa[i-1];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1, a; i <= N; i++)
        cin >> a, psa[i] = psa[i-1] + a;

    memset(dp, -1, sizeof(dp));
    
    cout << solve(1, N) << '\n';

    return 0;
}
