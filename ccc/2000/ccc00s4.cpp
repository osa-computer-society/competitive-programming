// Problem ID: 
// By 

#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

long long dp[5285];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 0, a; i < M; i++)
    {
        cin >> a;
        for (int w = a; w <= N; w++)
            dp[w] = min(dp[w], dp[w-a]+1);
    }
    if (dp[N] >= INF) cout << "Roberta acknowledges defeat.\n";
    else cout << "Roberta wins in " << dp[N] << " strokes.\n";

    return 0;
}
