// Problem ID: chairstacking
// By Alexander Cai
// Solved 3 Jan 2020

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, x, y;
    long long l = 0, r = 0, t = 0, b = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        l += abs(x-1);
        r += abs(x-M);
        t += abs(y-1);
        b += abs(y-M);
    }

    cout << max(l, r) + max(t, b);

    return 0;
}
