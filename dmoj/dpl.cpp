// Problem ID: dpl (Deque)
// By 
// Keywords: Dynamic Programming

#include <iostream>
#include <string.h>
#define MAXN 3005
using namespace std;
typedef long long ll;

int a[MAXN];
ll dp[MAXN][MAXN];

ll solve(int l, int r)
{
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(a[l] - solve(l+1, r), a[r] - solve(l, r-1));
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];

    cout << solve(1, N) << '\n';

    return 0;
}
