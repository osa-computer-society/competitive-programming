// solved

// standard DP approach
// process one stack of plates at a time

#include <iostream>
#include <cstring>
#define MAXN 55
#define MAXK 35
#define MAXP (MAXN*MAXK)
using namespace std;

int beauty[MAXN][MAXK], dp[MAXN][MAXP];

int main()
{
    int T;
    cin >> T;

    int N; // # stacks
    int K; // # plates per stack
    int P; // # plates to pick
    for (int t = 1; t <= T; t++)
    {
        memset(beauty, 0, sizeof(beauty));
        memset(dp, 0, sizeof(dp));

        cin >> N >> K >> P;
        for (int n = 1; n <= N; n++)
        {
            int total = 0;
            for (int k = 1; k <= K; k++)
            {
                int x;
                cin >> x;
                total += x;
                beauty[n][k] = total;
            }
        }

        for (int i = 1; i <= N; i++) // we use the first i stacks
            for (int j = 0; j <= P; j++) // j = total plates
                for (int k = 0; k <= min(K, j); k++) // k = number of plates from this stack
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k] + beauty[i][k]);

        cout << "Case #" << t << ": " << dp[N][P] << '\n';
    }
    return 0;
}
