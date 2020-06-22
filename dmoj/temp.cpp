#include <iostream>
#include <cstring>
#define MAXN 1000005
using namespace std;

int a[MAXN], rem[MAXN], r[MAXN], sm = MAXN, st;

int main() {
    int N, tot = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i]; tot += a[i];
        if (a[i] < sm) { sm = a[i], st = i; }
    }

    if (tot&1) { cout << "NO\n"; return 0; }

    for (int x = 0; x <= a[st]; x++)
    {
        memcpy(rem, a, sizeof(a));
        bool flag = true;
        int cnt = x;
        // Loop around the circle
        for (int i = 0, j = st; i < N; ++i, j = (j+1)%N)
        {
            rem[j] -= cnt, rem[(j+1)%N] -= cnt;
            if (rem[j] < 0 || rem[(j+1)%N] < 0) { flag = false; break; }
            r[j] = cnt, cnt = rem[(j+1)%N];
        }

        for (int i = 0; i < N; ++i)
            if (rem[i] != 0) flag = false;

        if (!flag) continue;

        cout << "YES\n" << (tot/2) << "\n";
        for (int i = 0, j = st; i < N; ++i, j = (j+1)%N)
            for (int k = 0; k < r[j]; ++k)
                cout << j << ' ' << (j+1)%N << '\n';

        return 0;
    }

    cout << "NO\n";

    return 0;
}