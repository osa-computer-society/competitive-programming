// Problem ID: 
// By 

#include <iostream>
#include <cstring>
using namespace std;

int X[205], dp[205][205];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0) break;

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= N; i++)
        {
            cin >> X[i];
        }

        for (int i = 1; i <= N-2; i++)
        {
            int j = i + 2;
            dp[i][j] = X[i] + X[i+1] + X[i+2];
        }

        for (int len = 4; len <= N; len++)
        {
            for (int i = 1; i <= N-len+1; i++)
            {
                int j = i + len - 1;
                for (int k = i+1; k <= j-1; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + X[i] + X[k] + X[j]);
                }
            }
        }

        cout << dp[1][N] << '\n';
    }

    return 0;
}
