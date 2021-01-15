// Solved
// ACK USE YOUR LONG LONGS

#include <iostream>
#include <cstring>
#define MAXN 1005
using namespace std;

long long diag[MAXN*2];

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        memset(diag, 0, sizeof(diag));
        
        for (int r = 1; r <= N; ++r) {
            for (int c = 1; c <= N; ++c) {
                int t;
                cin >> t;
                diag[c-r + N] += t;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= 2*N-1; ++i) {
            ans = max(ans, diag[i]);
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
