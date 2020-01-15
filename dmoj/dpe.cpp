// Problem ID: 
// By 

#include <iostream>
#include <vector>
#define MAXN 105
#define MAXS 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

int w[MAXN], v[MAXN];
ll dp[MAXS];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    int s = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
        s += v[i];
    }

    for (int i = 1; i <= s; i++)
        dp[i] = INF;

    for (int i = 0; i < N; i++) // for each item
        for (int val = s; val >= v[i]; val--)
            dp[val] = min(dp[val], dp[val-v[i]] + w[i]);

    for (int i = s; i >= 0; i--)
        if(dp[i] <= W)
        {
            cout << i << '\n';
            return 0;
        }

    return 0;
}
