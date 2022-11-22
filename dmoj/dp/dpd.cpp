// By Alexander Cai 2021-02-14

#include <iostream>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int maxw = 1e5 + 5;
ll dp[maxw];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    int w, v;
    FOR(i, 1, N)
    {
        cin >> w >> v;
        for (int k = W; k >= w; --k)
            dp[k] = max(dp[k], dp[k - w] + v);
    }

    cout << dp[W] << '\n';

    return 0;
}
