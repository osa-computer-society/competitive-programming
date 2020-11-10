/*
ID: a.cai61
TASK: inflate
LANG: C++14
*/

// solved 2020-09-11

#include <iostream>
#include <fstream>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXVAL 10005
#define MAXCLASSES 10005
using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");

int dp[MAXVAL];

int main()
{
    int totalweight, nclasses;
    fin >> totalweight >> nclasses;

    int w, v;
    FOR(i, nclasses)
    {
        fin >> v >> w;
        for (int j = w; j <= totalweight; ++j)
            dp[j] = max(dp[j], dp[j-w] + v);
    }

    int ans = -1;
    for (int i = 0; i <= totalweight; ++i)
        ans = max(ans, dp[i]);

    fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
