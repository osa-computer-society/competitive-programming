#include <iostream>
#include <algorithm>
#include <utility>
#define MAXW 1005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii w[MAXW];

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int W, N;
        cin >> W >> N;

        for (int i = 1; i <= W; ++i)
            cin >> w[i].first;

        sort(w + 1, w + W + 1);
        for (int i = 1; i <= W; ++i)
            w[i].second = i;

        // indices of furthest elements, b > a
        int a, b, mindist = 0x3f3f3f3f;
        for (int i = 1; i <= W - 1; ++i)
        {
            for (int j = i + 1; j <= W; ++j)
            {
                int dist = max(w[j].first - w[i].first, w[i].first + N - w[j].first);
                if (dist < mindist)
                    mindist = dist, a = i, b = j;
            }
        }

        // going forward
        int nbetween = w[b].second - w[a].second - 1;
        int ans;
        if (nbetween == 0)
            ans = w[(w[b].second + W / 2 - 1) % W + 1].first;
        else
            ans = w[w[a].second + W / 2].first;

        int total = 0;
        for (int i = 1; i <= W; ++i)
        {
            if (w[i].first > ans)
                total += min(w[i].first - ans, ans + N - w[i].first);
            else
                total += min(ans - w[i].first, w[i].first + N - ans);
        }

        cout << "Case #" << t << ": " << total << '\n';
    }

    return 0;
}
