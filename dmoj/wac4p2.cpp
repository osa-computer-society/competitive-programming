// Problem ID: wac4p2.cpp
// By 

#include <iostream>
#include <cstring>
#define MAXN 5005
#define INF 0x3f3f3f3f
#define INFL 9*1e18
#define MAXTOTAL 5005
using namespace std;
typedef pair<int,int> pii;
int v[MAXN], p[MAXN];
long long dp[MAXTOTAL];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long total = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> p[i];
        total += p[i];
    }

    for (int i = 1; i <= total; i++) dp[i] = INFL;
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = total; j >= p[i]; j--)
            dp[j] = min(dp[j], dp[j-p[i]] + v[i]/2+1);
    
    long long ans = INFL;
    for (long long i = total/2+1; i <= total; i++)
        ans = min(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}
