// Problem ID: vmss7wc16c4p3
// By Alexander Cai

#include <iostream>
#include <string>
using namespace std;

int dp[1005][1005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int D, I, R;
    cin >> D >> I >> R;
    string A, B;
    cin >> A >> B;
    int m = A.size(), n = B.size();

    for (int i = 1; i <= m; i++)
        dp[i][0] = i*D;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j*I;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j]+D, min(dp[i][j-1]+I, dp[i-1][j-1]+R));
    
    cout << dp[m][n] << '\n';

    return 0;
}
