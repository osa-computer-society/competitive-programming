// Problem ID: 
// By 

#include <iostream>
#define MAXN 105
#define MAXL 105
#define INF 0x3f3f3f3f
#define PREV i%2
#define CURR (i-1)%2
using namespace std;

int L[MAXN], t[MAXN][MAXL], x[MAXN][MAXL];
long long dp[MAXN][2];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, T;
    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i];
        for (int j = 1, a, b; j <= L[i]; j++)
        {
            cin >> a >> b;
            t[i][j] = t[i][j-1] + a;
            x[i][j] = x[i][j-1] + b;
        }
    }

    int turn = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= L[i]; j++)
        {
            for (int k = 1; k <= T; k++)
            {
                if (k >= t[i][j]) {
                    dp[k][turn] = max(dp[k][turn^1], max(dp[k-t[i][j]][turn^1] + x[i][j], dp[k][turn]));
                }
                else dp[k][turn] = max(dp[k][turn^1], dp[k][turn]);
            }
        }
        turn ^= 1;
    }

    cout << dp[T][turn^1] << '\n';

    return 0;
}
