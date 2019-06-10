#include <iostream>

using namespace std;

int main() {
    int n;
    double q, y, total;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q >> y;
        total += q * y;
    }

    cout << total;
    return 0;
}