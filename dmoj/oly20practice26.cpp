// Problem ID: oly20practice26.cpp
// By 

#include <iostream>
#include <algorithm>
using namespace std;

int x[20005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> x[i];
    sort(x, x+N, greater<int>());

    int total = 0;
    for (int i = 1; i <= N; i++) {
        total += x[i-1];
        if (total >= K) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}
