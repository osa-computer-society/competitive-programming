// Problem ID: 
// By 

#include <iostream>
using namespace std;

long long dp[1000005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 2, n; i <= N+1; i++)
    {
        cin >> n;
        dp[i] = max(dp[i-1], dp[i-2]+n);
    }

    cout << dp[N+1] << '\n';

    return 0;
}
