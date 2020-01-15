// Problem ID: 
// By 

#include <iostream>
#define MAXN 55
#define MAXS 1005
#define INF 0x3f3f3f3f
#define PREV i%2
#define CURR (i-1)%2
using namespace std;

int H[MAXN], E[MAXN], P[MAXN];
long long dp[2][MAXS], t[2][MAXS];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> H[i] >> E[i] >> P[i];
    
    int W;
    cin >> W;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
            dp[PREV][j] = dp[CURR][j], t[PREV][j] = t[CURR][j];

        for (int v = 0, w = P[i], cnt = 1; H[i] > 0 && w <= W; H[i] -= E[i], cnt++, w += P[i])
        {
            v += H[i];
            for (int j = w; j <= W; j++)
            {
                int val = dp[CURR][j-w]+v, dur = t[CURR][j-w]+cnt;
                if (val > dp[PREV][j])
                    dp[PREV][j] = val, t[PREV][j] = dur;
                else if (val == dp[PREV][j] && dur < t[PREV][j])
                    t[PREV][j] = dur;
            }
        }
    }

    cout << dp[N%2][W] << '\n' << t[N%2][W] << '\n';

    return 0;
}
