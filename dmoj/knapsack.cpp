// Problem ID: 
// By 

#include <iostream>
#include <cstring>
#define MAXW 5005
using namespace std;
typedef long long ll;

ll dp[MAXW];
int cnt[MAXW]; // Limited knapsack: use a counter array

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0, n, w, v; i < N; i++)
    {
        cin >> n >> w >> v; // n is number, w is weight/cost, v is value/profit
        memset(cnt, 0, sizeof(cnt));
        // Loop from left to right (same as infinite knapsack)
        // Create a counter array -- when you make this value, if you still have more, you can update, otherwise you cannot
        for (int j = w; j < MAXW; j++)
            if (dp[j-w]+v > dp[j] && cnt[j-w]+1 <= n)
                dp[j] = dp[j-w]+v, cnt[j] = cnt[j-w]+1;
    }

    for (int j = 1; j < MAXW; j++)
        dp[j] = max(dp[j], dp[j-1]);

    ll ans = -0x3f3f3f3f;
    for (int i = 0, c, f; i < M; i++)
    {
        cin >> c >> f;
        ans = max(ans, dp[c]-f);
    }
    cout << ans << '\n';

    return 0;
}
