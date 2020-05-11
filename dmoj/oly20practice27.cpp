// Problem ID: oly20practice27.cpp
// By 

#include <iostream>
using namespace std;

int N, T, x[21], sm = 0x3f3f3f3f;

void recurse(int total, int i)
{
    // for (int j = 0; j < i-1; j++) cout << '\t';
    // cout << total << '\n';
    if (total >= T) sm = min(sm, total - T);
    if (i > N) return;
    recurse(total, i+1); // don't include x[i]
    recurse(total + x[i], i+1); // include x[i]
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 1; i <= N; i++)
        cin >> x[i];

    recurse(0, 1);

    if (sm == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << sm << '\n';

    return 0;
}
