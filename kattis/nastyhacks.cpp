#include <iostream>
using namespace std;

int main() {
    int n, r, e, c, diff;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> e >> c;
        diff = e - c - r;
        if (diff > 0)
            cout << "advertise" << endl;
        else if (diff < 0)
            cout << "do not advertise" << endl;
        else
            cout << "does not matter" << endl;
    }
}