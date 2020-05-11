// Problem ID: 
// By 
// UNSOLVED

#include <iostream>
#include <cstring>
#define MAXW 5005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll dp[2][MAXW];
bool used[MAXW];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    for (int i = 1, v1, w1, v2, w2; i <= N; i++)
    {
        int curr = i%2, prev = (i+1)%2;
        cin >> v1 >> w1 >> v2 >> w2;
        memset(used, 0, sizeof(used));

        for (int j = w1; j <= W; j++)
            dp[curr][j] = dp[prev][j-w1]+v1, used[j] = 1;
        
        for (int j = w1+w2; j <= W; j++)
            if (used[j-w2])
                dp[curr][j] = max(dp[curr][j], dp[curr][j-w2]+v2);
        
        for (int j = 0; j <= W; j++) dp[curr][j] = max(dp[curr][j], dp[curr][j]);
    }

    ll ans = 0;
    for (int i = 0; i <= W; i++)
        ans = max(ans, dp[N%2][i]);
    cout << ans << "\n";

    return 0;
}
