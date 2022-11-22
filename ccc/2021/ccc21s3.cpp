// Problem ID:
// By Alexander Cai

#include <iostream>
#include <cmath>
#define FOR(i, a, b) for (long long i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int MAXP = 1e9 + 5;
ll dx[MAXP];
ll maxp = 0;

void printdx()
{
    FOR(i, 0, maxp)
    cout << dx[i] << ' ';
    cout << "\n";
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    ll p, w, d;
    FOR(i, 1, N)
    {
        cin >> p >> w >> d;
        if (p - d > 0)
        {
            dx[0] += (p - d) * w;
            dx[1] += -w;
            dx[p - d + 1] += w;
        }
        if (p + d + 1 < MAXP)
            dx[p + d + 1] += w;
        maxp = max(maxp, p);
    }

    FOR(p, 2, maxp)
    dx[p] += dx[p - 1];

    ll ans = dx[0];
    FOR(p, 1, maxp)
    dx[p] += dx[p - 1], ans = min(ans, dx[p]);

    cout << ans << '\n';

    return 0;
}
