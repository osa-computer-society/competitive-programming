// Problem ID:
// By Alexander Cai

#include <iostream>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const bool LEFT = 0, RIGHT = 1;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    char a, b;
    int steps;
    bool prev;
    while (true)
    {
        cin >> a >> b >> steps;
        a -= '0';
        b -= '0';
        if (a == 9 && b == 9 && steps == 999)
            break;
        if ((a + b) & 1)
        {
            cout << "left " << steps << '\n';
            prev = LEFT;
        }
        else if (a + b == 0)
        {
            cout << (prev == LEFT ? "left " : "right ") << steps << '\n';
        }
        else
        {
            cout << "right " << steps << '\n';
            prev = RIGHT;
        }
    }

    return 0;
}
