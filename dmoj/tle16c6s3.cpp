// Problem ID: 
// By 

#include <iostream>
#include <algorithm>
#define MAXN 2005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

pii x[MAXN];
ll dp[MAXN][MAXN][2], psa[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> x[i].first >> x[i].second;
        psa[i] = psa[i-1] + x[i].second;
    }
    
    ll ans = x[1].second;

    sort(x+1, x+N+1);

    for (int len = 2; len <= N; len++)
    {
        for (int l = 1; l <= N-len+1; l++)
        {
            int r = l+len-1;
            dp[l][r][0] = x[l].second + max(
                dp[l+1][r][0] - abs(x[l].first - x[l+1].first),
                dp[l+1][r][1] - abs(x[l].first - x[r].first)
            );
            dp[l][r][1] = x[r].second + max(
                dp[l][r-1][1] - abs(x[r-1].first - x[r].first),
                dp[l][r-1][0] - abs(x[l].first - x[r].first)
            );

            // cout << dp[l+1][r][0] << '-' << abs(x[l].first - x[l+1].first) << '\n';
            // cout << dp[l+1][r][1] << '-' << abs(x[l].first - x[r].first) << '\n';

            // cout << dp[l][r][0] << ' ' << dp[l][r][1] << '\n';

            if (dp[l][r][0] >= 0 || dp[l][r][1] >= 0)
                ans = max(ans, psa[r] - psa[l-1]);
        }
    }

    cout << ans << '\n';

    return 0;
}
