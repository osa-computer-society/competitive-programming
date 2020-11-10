// solved 2020-09-21

// brute force, implementation

// CARE: check for division by 0

#include <iostream>
#include <fstream>
#include <cstring>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");

int goal[4];
int ratios[5][5];

int main()
{
    FOR(i, 3)
        fin >> goal[i];
    FOR(i, 3)
    FOR(j, 3)
    fin >> ratios[i][j];

    // i[k] = number of bags of ratio k
    // tot[j] = amount of feed of type j
    // ans[k] = number of bags of ratio k
    int i[4], tot[4], ans[4], minsum = 0x3f3f3f3f, mult, coeff;
    bool found;
    for (i[1] = 0; i[1] < 100; ++i[1])
    for (i[2] = 0; i[2] < 100; ++i[2])
    for (i[3] = 0; i[3] < 100; ++i[3])
    {
        memset(tot, 0, sizeof(tot));
        found = true;
        mult = -1;
        FOR(j, 3) // j = type of feed
        {
            FOR(k, 3) // k = which ratio to use
                tot[j] += i[k] * ratios[k][j];

            if (goal[j] == 0)
            {
                if (tot[j] > 0)
                    found = false;
            }
            else if (tot[j] % goal[j] != 0)
                found = false;
            else
            {
                if (mult == -1)
                    mult = tot[j] / goal[j];
                else if (mult != tot[j] / goal[j])
                    found = false;
            }
        }

        if (found && i[1] + i[2] + i[3] > 0 && i[1] + i[2] + i[3] < minsum)
        {
            minsum = i[1] + i[2] + i[3];
            coeff = mult;
            memcpy(ans, i, sizeof(ans));
        }
    }

    if (minsum == 0x3f3f3f3f)
        fout << "NONE\n";
    else
        fout << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << coeff << '\n';

    fin.close();
    fout.close();
    return 0;
}
