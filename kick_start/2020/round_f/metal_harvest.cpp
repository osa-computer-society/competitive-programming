#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int T;
    cin >> T;

    pii intervals[100005];
    int N, K; // num intervals, num seconds per robot
    for (int i = 1; i <= T; ++i)
    {
        cin >> N >> K;

        for (int i = 1; i <= N; ++i)
            cin >> intervals[i].first >> intervals[i].second;

        sort(intervals + 1, intervals + N + 1);
        
        int ans = 1;
        int cursor = intervals[1].first;

        while (true)
        {
            cursor = lower_bound(intervals + 1, intervals + N + 1, make_pair(cursor + K, 0)) - intervals;
            if (cursor > N) break;
            ++ans;
            cursor = intervals[cursor].first;
        }

        cout << "Case #" << i << ": " << ans;
        cout << '\n';
    }
}
