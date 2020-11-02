/*
ID: a.cai61
TASK: milk3
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 21
using namespace std;

int y[3];
bool dp[MAXN][MAXN], ans[MAXN];

void pour(int *x, int from, int to, int *z)
{
    z[3-from-to] = x[3-from-to];
    if (x[from] + x[to] > y[to]) z[from] = x[from] + x[to] - y[to], z[to] = y[to];
    else z[from] = 0, z[to] = x[from] + x[to];
}

void backtrack(int *x)
{
    bool &seen = dp[x[1]][x[2]];
    if (seen) return;
    seen = true;
    if (x[0] == 0) ans[x[2]] = true;
    
    int z[3];
    for (int i = 0; i < 2; i++)
        for (int j = i+1; j < 3; j++)
        {
            pour(x, i, j, z);
            backtrack(z);
            pour(x, j, i, z);
            backtrack(z);
        }
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin >> y[0] >> y[1] >> y[2];
    int x[] = { 0, 0, y[2] };

    // c to a
    int z[3];
    pour(x, 2, 1, z);
    backtrack(z);
    pour (x, 2, 0, z);
    backtrack(z);

    int k = 0;
    for (int i = 0; i <= y[2]; i++)
    {
        if (ans[i])
        {
            if (k++) fout << ' ';
            fout << i;
        }
    }
    fout << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
