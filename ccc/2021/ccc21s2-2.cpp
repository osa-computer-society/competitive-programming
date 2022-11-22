// By Alexander Cai 2021-02-17

// O(M + N)

#include <iostream>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int maxn = 5e6;
bool nrflip[maxn], ncflip[maxn];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    cin >> M >> N >> K;

    char ch;
    FOR(i, 1, K)
    {
        cin >> ch;
        if (ch == 'R')
        {
            int r;
            cin >> r;
            nrflip[r] = !nrflip[r];
        }
        else if (ch == 'C')
        {
            int c;
            cin >> c;
            ncflip[c] = !ncflip[c];
        }
    }

    ll rtotal = 0, ctotal = 0;
    FOR(r, 1, M)
    rtotal += nrflip[r];
    FOR(c, 1, N)
    ctotal += ncflip[c];
    cout << ctotal * (M - rtotal) + rtotal * (N - ctotal) << '\n';

    return 0;
}
