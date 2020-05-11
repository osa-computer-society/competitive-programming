// Problem ID: usaco20marb1.cpp
// By 

#include <iostream>
#include <algorithm>
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;

int ones[MAXN], twos[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt = 0, prev = 0, maxd = INF;
    char c;
    for (int i = 1; i <= N; i++)
    {
        cin >> c;
        if (c=='1')
        {
            if (prev == 0)
            {
                ones[cnt] = i-1;
                twos[cnt] = (i-1)/2;
            }
            else
            {
                ones[cnt] = (i-prev) / 2;
                twos[cnt] = (i-prev) / 3;
                maxd = min(maxd, i-prev);
            }
            prev = i;
            cnt++;
        }
    }

    if (cnt == 0)
    {
        cout << N-1 << '\n';
        return 0;
    }
    
    ones[cnt] = N-prev;
    twos[cnt] = (N-prev) / 2;

    // cout << "maxd: " << maxd << '\n';

    // for (int i = 0; i <= cnt; ++i) cout << ones[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i <= cnt; ++i) cout << twos[i] << ' ';
    // cout << '\n';

    sort(ones, ones+cnt+1, greater<int>());
    sort(twos, twos+cnt+1, greater<int>());

    // cout << '\n';
    // for (int i = 0; i <= cnt; ++i) cout << ones[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i <= cnt; ++i) cout << twos[i] << ' ';
    // cout << '\n';
    
    int maxdones = min(min(maxd, ones[0]), ones[1]);
    int maxdtwos = min(maxd, twos[0]);

    cout << max(maxdones, maxdtwos) << '\n';

    return 0;
}
