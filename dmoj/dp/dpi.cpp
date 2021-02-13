// Problem ID: 
// By 

#include <iostream>
#include <iomanip>
#define MAXN 3005
using namespace std;
typedef long double ld;

ld p[MAXN], dp[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> p[i];

    dp[0] = 1;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j >= 1; j--)
            dp[j] = dp[j-1]*p[i] + dp[j]*(1-p[i]);
        dp[0] *= (1-p[i]);
    }

    ld ans = 0;
    for (int i = N/2+1; i <= N; i++)
        ans += dp[i];
    
    cout << setprecision(10) << ans << '\n';

    return 0;
}
