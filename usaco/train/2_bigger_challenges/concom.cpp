/*
ID: a.cai61
TASK: concom
LANG: C++14
*/

// solved

// tricky recursion

#include <iostream>
#include <fstream>
#define MAXN 105
using namespace std;

int N;
bool c[MAXN][MAXN]; // c[u][v] := u owns v
int pc[MAXN][MAXN]; // p[u][v] := percentage of v owned by u, directly or indirectly

ifstream fin("concom.in");
ofstream fout("concom.out");

void update(int u, int v)
{
    if (c[u][v]) return;
    c[u][v] = true;
    for (int i = 1; i < MAXN; ++i)
        pc[u][i] += pc[v][i];
    for (int i = 1; i < MAXN; ++i)
        if (c[i][u])
            update(i, v);
    for (int i = 1; i < MAXN; ++i)
        if (pc[u][i] > 50)
            update(u, i);
}

int main()
{
    fin >> N;

    // each country controls itself
    for (int i = 1; i < MAXN; ++i)
        c[i][i] = true;

    int u, v, p;
    for (int i = 1; i <= N; ++i)
    {
        fin >> u >> v >> p;
        // for each company j that controls u,
        // (indirectly through u) it owns p percent more of v
        for (int j = 1; j < MAXN; ++j)
            if (c[j][u])
                pc[j][v] += p;
        for (int j = 1; j < MAXN; ++j)
            if (pc[j][v] > 50)
                update(j, v);
    }

    for (int i = 1; i < MAXN; ++i)
        for (int j = 1; j < MAXN; ++j)
            if (i != j && c[i][j])
                fout << i << ' ' << j << '\n';

    fin.close();
    fout.close();
    return 0;
}
