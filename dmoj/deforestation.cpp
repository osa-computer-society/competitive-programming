// DMOPC '14 Contest 2 P4 - Deforestation
// By Alexander Cai 2019-11-30

#include <iostream>

using namespace std;

int trees[1000001];
int sums[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, i, a, b, t;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> trees[i];
        t += trees[i];
        sums[i] = t;
    }

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << sums[b] - sums[a] + trees[a] << "\n";
    }
    return 0;
}

