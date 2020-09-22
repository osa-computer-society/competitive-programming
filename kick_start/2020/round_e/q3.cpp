#include <iostream>
#include <utility>
#include <vector>
#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pii toys[MAXN];
vector<pii> all;

int N;
ll sum[MAXN];
ll y, z;

void rec(int n)
{
    if (n == N)
    {
        int nn = all.size(); // number of toys
        if (nn == 0) return;

        int yy = N - nn; // number of removed toys

        sum[0] = 0;
        for (int i = 1; i <= nn; ++i)
            sum[i] = sum[i - 1] + all[i - 1].first;
        
        for (int i = 1; i <= nn; ++i)
            if (sum[nn] - all[i - 1].first < all[i - 1].second) // if we can't loop back around
            {
                ll zz = sum[nn] + sum[i - 1];
                if (zz > z || (zz == z && yy < y))
                    y = yy, z = zz;
                return;
            }

        // going here mean all can loop around, we have infinite
        if (z < INF || (z == INF && yy < y))
            y = yy, z = INF;
        return;
    }

    rec(n + 1);
    all.push_back(toys[n+1]);
    rec(n + 1);
    all.pop_back();
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> toys[i].first >> toys[i].second;
        
        y = INF, z = -1;
        rec(0);

        cout << "Case #" << t << ": " << y << ' ';
        if (z == INF) cout << "INDEFINITELY";
        else cout << z;
        cout << '\n';
    }
    return 0;
}