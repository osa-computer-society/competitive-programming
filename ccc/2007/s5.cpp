// Problem ID: 
// By 

#include <iostream>
#include <cstring>
#define MAXN 30005
using namespace std;

int N, K, W;
int dp[2][MAXN];
int pin_vals[MAXN], psa[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    psa[0] = 0;

    int T;
    cin >> T;
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> N >> K >> W;
        int total = 0;
        for (int i = 1; i <= N; i++)
        {
            cin >> pin_vals[i];
            total += pin_vals[i];
            psa[i] = total;
        }

        for (int k = 1; k <= K; k++)
        {
            for (int i = 1; i <= N; i++)
                dp[1][i] = max(dp[1][i-1], psa[i] - psa[max(i-W, 0)] + dp[0][max(i-W, 0)]);
            for (int i = 1; i <= N; i++)
                dp[0][i] = dp[1][i];
            memset(dp[1], 0, sizeof(dp[1]));
        }

        cout << dp[0][N] << '\n';
    }

    return 0;
}
