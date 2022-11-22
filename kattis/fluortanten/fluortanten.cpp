#include <iostream>
#include <vector>
#define MAXN 10000005

typedef long long ll;
using namespace std;

int main()
{
    int count;
    cin >> count;

    ll total = 0, weighted_total = 0, min_total = 0;
    int i = 0;
    int t;
    for (int _ = 1; _ <= count; ++_)
    {
        cin >> t;
        if (t == 0)
            continue;
        ++i;
        total += t;
        weighted_total += i * t;
        if (total < min_total)
            min_total = total;
    }

    cout << weighted_total + total - min_total << '\n';

    return 0;
}