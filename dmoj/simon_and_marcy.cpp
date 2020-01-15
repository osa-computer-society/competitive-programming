// Problem ID: 
// By Alexander Cai

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1003][1003];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int C, M, n, k;
    cin >> C >> M;

    for (int i = 0; i <= C; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= M; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= C; i++)
    {
        cin >> n >> k;
        for (int w = 1; w <= M; w++)
            if (k > w)
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(n + dp[i-1][w-k], dp[i-1][w]);
    }

    cout << dp[C][M] << "\n";
    return 0;
}
