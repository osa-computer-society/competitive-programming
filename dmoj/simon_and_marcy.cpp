#include <iostream>

using namespace std;

int dp[1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int C, M, n, k, i;
    cin >> C >> M;

    while (C--) {
        cin >> n >> k;
        for (i = M; i >= 0; --i)
            if (i >= k)
                dp[i] = max(dp[i], dp[i-k] + n);
    }

    cout << dp[M] << "\n";
    return 0;
}
