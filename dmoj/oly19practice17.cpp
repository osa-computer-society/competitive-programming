// Problem ID: oly19practice17.cpp
// By 

#include <iostream>
#define MAXN 100005
using namespace std;

int cnt[MAXN], dp[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int maxn = -1;

    for (int i = 0, x; i < N; i++)
    {
        cin >> x;
        cnt[x]++;
        maxn = max(maxn, x);
    }

    for (int i = 1; i <= maxn; i++)
    {
        dp[i] = max(i*cnt[i] + dp[i-2], dp[i-1]);
    }

    cout << dp[maxn] << '\n';

    return 0;
}
