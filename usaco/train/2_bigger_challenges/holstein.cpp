/*
ID: a.cai61
TASK: holstein
LANG: C++14
*/

// solved 2020-08-06

#include <iostream>
#include <fstream>
#define MAXV 25
#define MAXG 15
using namespace std;

int V, G, v[MAXV + 5], g[MAXG + 5][MAXV + 5];
int sol = 0x3f3f3f3f, ans;

bool valid_solution(int *vit)
{
    for (int i = 1; i <= V; i++)
        if (vit[i] < v[i])
            return false;
    return true;
}

void recurse(int mask, int k, int n, int *vit)
{
    if (valid_solution(vit))
    {
        if (n < sol) // valid solution
            sol = n, ans = mask;
    }
    else if (k <= G)
    {
        // include
        int temp[MAXV + 5];
        for (int i = 1; i <= V; i++)
            temp[i] = vit[i] + g[k][i];
        recurse(mask | (1 << k), k + 1, n + 1, temp);
        // don't include
        recurse(mask, k + 1, n, vit);
    }
}

int main()
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    fin >> V;
    for (int i = 1; i <= V; i++)
        fin >> v[i];
    fin >> G;
    for (int i = 1; i <= G; i++)
        for (int j = 1; j <= V; j++)
            fin >> g[i][j];

    int vit[MAXV + 5] = {0};
    recurse(0, 1, 0, vit);

    fout << sol;
    for (int i = 1; i <= G; i++)
        if (ans & (1 << i))
            fout << ' ' << i;
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
