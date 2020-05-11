// Problem ID: vmss7wc15c1p2.cpp
// By 

#include <iostream>
using namespace std;

int x[61];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int L;
    while (N--) {
        cin >> L;
        int total = 0;
        for (int i = 1; i <= L; i++)
            cin >> x[i];
        for (int i = 1; i < L; i++)
        {
            for (int j = i+1; j <= L; j++)
                if (x[i] > x[j]) total++;
        }
        cout << total << '\n';
    }

    return 0;
}
