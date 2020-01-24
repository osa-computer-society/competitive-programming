// Problem ID: 
// By 

#include <iostream>
#define MAXN 405
using namespace std;
typedef long long ll;

ll psa[MAXN];
bool dp[MAXN][MAXN];
ll ans;

void set_dp(int i, int j)
{
    dp[i][j] = true;
    ans = max(ans, psa[j] - psa[i-1]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    ll total = 0;
    for (int i = 1, n; i <= N; i++)
    {
        cin >> n;
        total += n;
        psa[i] = total;
        set_dp(i, i);
    }

    for (int i = 1; i <= N-1; i++)
    {
        int j = i+1;
        if (psa[i]-psa[i-1] == psa[j]-psa[j-1])
            set_dp(i, j);
    }

    for (int len = 3; len <= N; len++)
    {
        for (int i = 1; i <= N-len+1; i++)
        {
            int j = i+len-1;
            for (int k = i; k <= j-1; k++)
            {
                if (dp[i][k] && dp[k+1][j] && psa[k]-psa[i-1] == psa[j]-psa[k])
                {
                    set_dp(i, j);
                    break;
                }
            }

            if (dp[i][j]) continue;

            int p = i, q = j;
            while (p + 1 <= q - 1)
            {
                ll l = psa[p] - psa[i-1];
                ll r = psa[j] - psa[q-1];
                if (dp[i][p] && dp[q][j] && dp[p+1][q-1] && l == r)
                {
                    set_dp(i, j);
                    break;
                }
                else if (l > r) q--;
                else p++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
