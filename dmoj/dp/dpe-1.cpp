// By Alexander Cai 2021-02-14

#include <iostream>
#include <cstring>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int maxv = 1e3 * 100 + 5;

int dp[maxv]; // dp[i] = minimum weight needed to get value i

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    int w, v;
    FOR(i, 1, N)
    {
        cin >> w >> v;
        for (int k = maxv-1; k >= v; --k)
            dp[k] = min(dp[k], dp[k - v] + w);
    }

    for (int i = maxv-1; i >= 0; --i)
        if (dp[i] <= W)
        {
            cout << i << '\n';
            break;
        }

    return 0;
}
