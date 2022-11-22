// By Alexander Cai 2021-02-13

#include <iostream>
using namespace std;

const int maxn = 1e5+5;
int h[maxn], dp[maxn];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    for (int i = 3; i <= N; ++i)
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    
    cout << dp[N] << '\n';

    return 0;
}
