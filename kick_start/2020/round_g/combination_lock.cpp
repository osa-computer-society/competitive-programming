#include <iostream>
#include <cstring>
#define MAXN 1005
using namespace std;

int dist[MAXN];

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int W, N;
        cin >> W >> N;
        memset(dist, 0, sizeof(dist));

        for (int i = 1; i <= W; ++i)
        {
            int w;
            cin >> w;

            for (int j = 1; j <= N; ++j)
            {
                if (j < w)
                    dist[j] += min(w - j, (j + N - w) % N);
                else
                    dist[j] += min(j - w, (w + N - j) % N);
            }
        }

        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= N; ++i)
        {
            ans = min(ans, dist[i]);
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
