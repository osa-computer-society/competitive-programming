// Solved by Alexander Cai 2021-02-13

#include <iostream>
#include <cstring>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;

const int maxn = 1e5 + 5;
int h[maxn], dp[maxn];

int main() {
    int N, K;
    cin >> N >> K;

    FOR(i, 1, N) cin >> h[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    FOR(i, 2, N)
    {
        for (int k = 1; k <= min(K, i-1); ++k)
            dp[i] = min(dp[i], dp[i-k] + abs(h[i] - h[i-k]));
    }

    cout << dp[N] << '\n';

    return 0;
}