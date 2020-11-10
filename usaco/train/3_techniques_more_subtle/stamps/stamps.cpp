// solved 2020-09-20

// straightforward unbounded DP

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXVAL 200*10000
using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int vals[55], dp[MAXVAL];

int main()
{
    int K, N; // max total stamps, num types of stamps
    fin >> K >> N;
    FOR(i, N) fin >> vals[i];
    sort(vals+1, vals+N+1, greater<int>());

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    FOR(i, N)
        for (int v = vals[i]; v <= MAXVAL; ++v)
            dp[v] = min(dp[v], dp[v-vals[i]] + 1);

    for (int i = 0; i <= MAXVAL; ++i)
    {
        if (dp[i] > K)
        {
            fout << i-1 << '\n';
            break;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
