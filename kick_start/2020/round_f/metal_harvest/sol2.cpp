#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

pii intervals[100005];

int main()
{
    int T;
    cin >> T;

    int N, K;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> K;
        for (int i = 1; i <= N; ++i)
            cin >> intervals[i].first >> intervals[i].second;
        sort(intervals + 1, intervals + N + 1);

        // cur = the current starting position of the robot
        // ans = the number of robots
        int cur = 0, ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            cur = max(cur, intervals[i].first);
            while (cur < intervals[i].second)
                ++ans, cur += K;
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}