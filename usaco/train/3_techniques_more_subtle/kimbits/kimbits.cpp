/*
ID: a.cai61
TASK: kimbits
LANG: C++14
*/

// solved

// dynamic programming, recursion

#include <iostream>
#include <fstream>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXN 35
using namespace std;
typedef long long ll;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

ll nck[MAXN][MAXN];

void rec(int n, int l, ll i)
{
    if (n <= 0)
        return;

    if (i > nck[n - 1][l])
    {
        fout << '1';
        rec(n - 1, l - 1, i - nck[n - 1][l]);
    }
    else
    {
        fout << '0';
        rec(n - 1, l, i);
    }
}

int main()
{
    int N, L;
    ll I;
    fin >> N >> L >> I;

    for (int i = 0; i < MAXN; ++i)
    {
        nck[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
        for (int j = i + 1; j < MAXN; ++j)
            nck[i][j] = nck[i][j - 1];
    }

    rec(N, L, I);
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
