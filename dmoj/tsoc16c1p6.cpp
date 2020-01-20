// Problem ID: tsoc16c1p6
// By Alexander Cai with help from https://github.com/jimgao1/competitive-programming/blob/master/DMOJ/tsoc16c1p6.cpp

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
using namespace std;

int N, M, dp[1005][1005];
string A, B;

int solve(int i, int j)
{
    if (i < 0 || j < 0) return 0x3f3f3f3f;
    if (i == 0 && j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (A[i-1] == B[j-1]) return dp[i][j] = solve(i-1, j-1);

    int ans = solve(i-1, j-1)+1;
    for (int k = 1; k <= 3; k++)
    {
        ans = min(ans, solve(i-k, j) + 1);
        ans = min(ans, solve(i, j-k) + 1);
    }
    return dp[i][j] = ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> A >> B;

    memset(dp, -1, sizeof(dp));

    cout << solve(N, M) << '\n';

    return 0;
}
