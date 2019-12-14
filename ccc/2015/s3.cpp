#include <iostream>

using namespace std;

int main()
{
    int G, P, k, t, total = 0;
    cin >> G >> P;
    int cnt[G+5]; // keeps track of the number of planes at this gate or below
    for (int i = 0; i < P; i++)
    {
        cin >> k;
        while (k > 0 and cnt[k] > 0)
        {
            t = cnt[k];
            cnt[k]++;
            k -= t;
        }
        if (k <= 0) break;
        cnt[k] = 1;
        total++;
    }
    cout << total;
}