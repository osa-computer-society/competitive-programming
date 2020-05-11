// Problem ID: oly19practice47.cpp
// By Alexander Cai

#include <iostream>
#include <math.h>
#include <algorithm>
#define MAXN 2001
#define L 0
#define R 1
using namespace std;

long long dp[MAXN][MAXN][2];
int x[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; ++i)
    {
        cin >> x[i];
    }

    sort(x+1, x+N+1);

    for (int i = 1; i <= N; ++i)
    {
        dp[i][i][L] = dp[i][i][R] = abs(x[i]-S)*N;
    }

    for (int n = 2; n <= N; ++n)
    {
        for (int l = 1; l <= N-n+1; ++l)
        {
            int r = l+n-1;

            dp[l][r][L] = min(
                dp[l+1][r][L] + (x[l+1]-x[l])*(N-n+1),
                dp[l+1][r][R] + (x[r]-x[l])*(N-n+1)
            );
            dp[l][r][R] = min(
                dp[l][r-1][R] + (x[r]-x[r-1])*(N-n+1),
                dp[l][r-1][L] + (x[r]-x[l])*(N-n+1)
            );
        }
    }
    
    cout << min(dp[1][N][R], dp[1][N][L]) << '\n';

    return 0;
}
