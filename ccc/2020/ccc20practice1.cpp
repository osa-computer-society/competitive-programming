// Problem ID: ccc20practice1.cpp
// By 

#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt = 0;
    for (int i = max(N-5, 0); i <= 5 && i <= N-i; i++)
        cnt++;

        cout << cnt << '\n';

    return 0;
}
