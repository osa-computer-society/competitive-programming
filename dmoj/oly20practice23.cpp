// Problem ID: oly20practice23.cpp
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
    for (int i = 1; i*i < N; i++)
    {
        if (N % i == 0 && (i%2 == N/i % 2))
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
