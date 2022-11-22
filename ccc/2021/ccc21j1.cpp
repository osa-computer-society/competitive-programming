#include <iostream>
using namespace std;

int main()
{
    int B;
    cin >> B;
    int P = 5 * B - 400;
    cout << P << '\n';
    // with ternary statement:
    // cout << (P < 100 ? 1 : (P > 100 ? -1 : 0)) << '\n';
    if (P < 100)
        cout << 1;
    else if (P > 100)
        cout << -1;
    else
        cout << 0;
    cout << '\n';
    return 0;
}