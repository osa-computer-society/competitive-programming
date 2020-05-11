// Problem ID: oly20practice25.cpp
// By 

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int s, t, r;
    while (K--)
    {
        cin >> s >> t >> r;
        float hrs = (float)N / (float)(s);
        int nbreaks = hrs / (float)t;
        cout << ceil(hrs) + nbreaks * r << '\n';
    }

    return 0;
}
