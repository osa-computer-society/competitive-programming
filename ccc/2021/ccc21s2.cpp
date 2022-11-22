// By Alexander Cai 2021-02-17

// O(MN) solution
// even/odd for each row on/off
// loop through entire grid, tally for each cell

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

    ll total = 0;
    FOR(r, 1, M)
    {
        FOR(c, 1, N)
        {
            if (nrflip[r] ^ ncflip[c])
            {
                total++;
            }
        }
    }
    cout << total << '\n';

    return 0;
}
