// By Alexander Cai and Tawfeeq Mannan 2021-02-17

// O(K)

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

    int rtotal = 0, ctotal = 0;
    char ch;
    FOR(i, 1, K)
    {
        cin >> ch;
        if (ch == 'R')
        {
            int r;
            cin >> r;
            if (nrflip[r]) // already on
                rtotal--;
            else
                rtotal++;
            nrflip[r] = !nrflip[r];
        }
        else if (ch == 'C')
        {
            int c;
            cin >> c;
            if (ncflip[c])
                ctotal--;
            else
                ctotal++;
            ncflip[c] = !ncflip[c];
        }
    }

    cout << ctotal * (M - rtotal) + rtotal * (N - ctotal) << '\n';

    return 0;
}
