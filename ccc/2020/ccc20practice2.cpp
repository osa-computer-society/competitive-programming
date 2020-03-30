// Problem ID: ccc20practice2.cpp
// By 

#include <iostream>
#define MAXN 100005
using namespace std;

int x[MAXN], y[MAXN];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1, t; i <= N; i++)
        cin >> t, x[i] = x[i-1]+t;
    for (int i = 1, t; i <= N; i++)
        cin >> t, y[i] = y[i-1]+t;
    

    for (int i = N; i >= 0; i--)
        if (x[i] == y[i])
        {
            cout << i << '\n';
            return 0;
        }

    return 0;
}
