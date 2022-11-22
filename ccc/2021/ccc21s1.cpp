// Problem ID:
// By Alexander Cai

#include <iostream>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int maxn = 10005;
long double h[maxn], w[maxn];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    FOR(i, 1, N + 1)
    cin >> h[i];

    FOR(i, 1, N)
    cin >> w[i];

    long double total = 0;
    FOR(i, 1, N)
    {
        long double area = (h[i] + h[i + 1]) * w[i] / (long double)2;
        // cout << area << '\n';
        total += area;
    }

    cout << total << '\n';

    return 0;
}
