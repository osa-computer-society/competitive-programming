// Problem ID: oly20practice24.cpp
// By 

#include <iostream>
#include <algorithm>
#define MAXN 50005
using namespace std;

int x[MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T >> N;

    for (int i = 1; i <= N; i++) cin >> x[i];

    sort(x+1, x+1+N, [](int a, int b) { return abs(a) < abs(b); });

    int total = 0;
    for (int i = 1; i <= N; i++) {
        total += abs(x[i] - x[i-1]);
        if (total > T) {
            cout << i-1 << '\n';
            return 0;
        }
    }

    cout << N << '\n';

    return 0;
}
