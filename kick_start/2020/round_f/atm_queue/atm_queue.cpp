// code by Alexander Cai 2020-09-26
// solved

#include <iostream>
#include <utility>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef pair<int, int> pii;

pii queue[MAXN];

int main()
{
    int T;
    cin >> T;

    int N; // number of people
    int A; // temporary variable for storing how much money each person needs
    int X; // max amount of money that can be withdrawn at a time
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> X;
        for (int i = 1; i <= N; ++i)
        {
            cin >> A;
            queue[i] = make_pair((A - 1) / X, i);
        }
        sort(queue + 1, queue + N + 1);

        cout << "Case #" << t << ":";
        for (int i = 1; i <= N; ++i)
            cout << ' ' << queue[i].second;
        cout << '\n';
    }

    return 0;
}
