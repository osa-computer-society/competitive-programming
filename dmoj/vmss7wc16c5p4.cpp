// Problem ID: 
// By Alexander Cai

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[100005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, item[3];
    cin >> N >> item[0] >> item[1] >> item[2];

    dp[0] = 0;
    for (int i = 1; i <= N; i++)
        dp[i] = -0x3f3f3f3f;

    for (int i = 0; i < 3; i++)
        for (int w = item[i]; w <= N; w++)
            dp[w] = max(dp[w], 1+dp[w-item[i]]);

    cout << dp[N] << "\n";
    return 0;
}
