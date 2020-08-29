/*
ID: a.cai61
TASK: money
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <string.h>
#define MAXV 30
#define MAXN 10005
using namespace std;
typedef long long ll;

ll dp[MAXN];

ifstream fin("money.in");
ofstream fout("money.out");

int main()
{
    int V, N;
    fin >> V >> N;
    dp[0] = 1;
    int v;
    for (int i = 1; i <= V; ++i)
    {
        fin >> v;
        for (int j = v; j <= N; ++j)
            dp[j] += dp[j-v];
    }

    fout << dp[N] << '\n';

    fin.close();
    fout.close();
    return 0;
}
