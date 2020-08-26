// solved

// backward math

#include <iostream>
using namespace std;
typedef long long ll;

ll X[1005];

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        ll D;
        cin >> N >> D;
        for (int i = 1; i <= N; i++)
            cin >> X[i];
        
        ll start = D;
        for (int i = N; i >= 1; i--)
            start = X[i] * (start / X[i]);
        cout << "Case #" << t << ": " << start << '\n';
    }
    return 0;
}