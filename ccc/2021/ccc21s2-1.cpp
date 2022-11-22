// By Alexander Cai 2021-02-17

// O(K (log M + log N))

#include <iostream>
#include <set>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

set<int> nrflip, ncflip;

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
            if (nrflip.count(r))
                nrflip.erase(r);
            else
                nrflip.insert(r);
        }
        else if (ch == 'C')
        {
            int c;
            cin >> c;
            if (ncflip.count(c))
                ncflip.erase(c);
            else
                ncflip.insert(c);
        }
    }

    ll total = nrflip.size() * (N - ncflip.size()) + ncflip.size() * (M - nrflip.size());

    cout << total << '\n';

    return 0;
}
