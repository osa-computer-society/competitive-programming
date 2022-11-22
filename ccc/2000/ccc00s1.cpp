// solved 2021-02-17 Alexander Cai

#include <iostream>

using namespace std;

int main()
{
    int amt[] = {30, 60, 9};
    int ntimes[] = {35, 100, 10};
    int nquarters, x[3];
    cin >> nquarters >> x[0] >> x[1] >> x[2];

    int nsteps = 0;
    int cur = 0;
    while (nquarters > 0)
    {
        nquarters--;
        nsteps++;
        x[cur]++;
        if (x[cur] % ntimes[cur] == 0)
        {
            nquarters += amt[cur];
            x[cur] = 0;
        }
        cur++;
        cur %= 3;
    }

    cout << "Martha plays " << nsteps << " times before going broke.\n";
    return 0;
}