// Problem ID: 
// By 

#include <iostream>
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
            for (int i = 1; i <= N-len; i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(dp[i][j-1] + X[i] + X[j-1] + X[j], dp[i+1][j] + X[i] + X[i+1] + X[j]);
            }
        }

        cout << dp[1][N] << '\n';
    }

    return 0;
}
