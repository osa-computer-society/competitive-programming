// solved with analysis
// By Alexander Cai 2020-09-27

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#define MAXN 100005
using namespace std;
typedef pair<int, int> pii;

pii intervals[MAXN];

int main()
{
    int T;
    cin >> T;

    int N, K; // num intervals, num seconds per robot
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> K;

        for (int i = 1; i <= N; ++i)
            cin >> intervals[i].first >> intervals[i].second;

        sort(intervals + 1, intervals + N + 1);
        
        int ans = 0; // the number of robots we need
        int lasttime = 0;

        for (int i = 1; i <= N; ++i)
        {
            if (intervals[i].second-1 < lasttime)
                continue;
            int numrobots = ceil((double) (intervals[i].second - max(intervals[i].first, lasttime)) / (double) K);
            ans += numrobots;
            lasttime = max(lasttime, intervals[i].first) + numrobots * K;
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
