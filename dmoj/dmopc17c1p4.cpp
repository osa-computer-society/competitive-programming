// Problem ID: 
// By 

#include <iostream>
#define MAXW 5005
#define PREV i%2
#define CURR (i-1)%2
using namespace std;
typedef long long ll;
ll dp[2][MAXW];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;
    for (int i = 1, v1, w1, v2, w2; i <= N; i++)
    {
        cin >> v1 >> w1 >> v2 >> w2;
        for (ll v = v1, w = w1; w <= W; v += v2, w += w2)
            for (int j = W; j >= w; j--)
                dp[1][j] = max(dp[PREV][j], max(dp[CURR][j], dp[PREV][j-w]+v));
        for (int j = 1; j <= W; j++)
            dp[PREV][j] = dp[CURR][j];
    }

    cout << dp[N%2][W] << '\n';

    return 0;
}
