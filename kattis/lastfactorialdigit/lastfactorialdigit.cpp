#include <iostream>
using namespace std;

int main() {
    int t, n, tot, i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        tot = 1;
        for (j = n; j > 1; j--)
            tot = (tot * j) % 10;
        cout << tot << endl;
    }
}
