// Problem ID: ccc05p5
// By Alexander Cai

#include <iostream>
#define MAXN 20000
using namespace std;
int dp[2][2];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int l, r, pl, pr;
    cin >> l >> r;
    dp[0][0] = l + 2*(r-l) - 1;
    dp[0][1] = r - 1;
    pl = l, pr = r;

    for (int i = 2; i <= N; i++)
    {
        cin >> l >> r;
        dp[1][0] = 1 + r-l + min(
            dp[0][1] + abs(pr-r),
            dp[0][0] + abs(pl-r)
        );
        dp[1][1] = 1 + r-l + min(
            dp[0][0] + abs(pl-l),
            dp[0][1] + abs(pr-l)
        );
        pl = l, pr = r;
        dp[0][0] = dp[1][0], dp[0][1] = dp[1][1];
    }

    cout << min(dp[0][1] + N-r, dp[1][1] + N-l) << '\n';

    return 0;
}
