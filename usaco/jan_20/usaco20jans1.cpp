// Problem ID: 
// By 

#include <iostream>
#include <algorithm>
using namespace std;

int B[1005], b = 1;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K, lgb = -1;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> B[i], lgb = max(lgb, B[i]);

    sort(B+1, B+N+1);

    int ans = -1;
    for (; b <= lgb; b++)
    {
        int tot = 0; // # of baskets
        for (int i = 1; i <= N; i++)
            tot += B[i] / b;
        if (tot < K/2)
            break;
        if (tot >= K)
        {
            ans = max(ans, b * K/2);
            continue;
        }
        sort(B+1, B+N+1, [](int u, int v){return u%b > v%b;});
        int bessie = b * (tot-K/2);
        for (int i = 1; i <= N && tot+i<=K; i++)
            bessie += B[i]%b;
        ans = max(ans, bessie);
    }

    cout << ans << '\n';

    return 0;
}
