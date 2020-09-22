#include <iostream>
#include <cstring>
#define MAXN 100005
using namespace std;

int sum[MAXN], E[MAXN], R[MAXN];

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        sum[0] = 0;
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> E[i] >> R[i];
            sum[i] = sum[i - 1] + E[i];
        }

        for (int i = 1; i <= N; i++)
        {
            bool can_return = sum[N] - E[i] >= R[i];
        }



        // cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}