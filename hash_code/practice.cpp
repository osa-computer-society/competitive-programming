// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100005
#define MAXM 1000000005
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    int dp[N+5][M+5];
    int w[N+5];

    for (int i = 0; i <= M; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = 0;
        cin >> w[i];
        for (int j = 1; j < w[i]; j++)
            dp[i][j] = dp[i-1][j];

        for (int j = w[i]; j <= M; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+w[i]);

        // for (int j = 1; j <= M; j++)
        //     cout << dp[i][j] << ' ';
        // cout << '\n';
    }

    int i = N, j = M;
    vector<int> ans;
    while (j > 0 && i > 0)
    {
        while (dp[i][j] == dp[i-1][j]) i--;
        ans.push_back(i);
        j -= w[i];
        i--;
    }

    cout << ans.size() << '\n';
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it-1 << ' ';
    cout << '\n';

    return 0;
}
