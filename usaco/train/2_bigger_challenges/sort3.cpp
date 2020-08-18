/*
ID: a.cai61
TASK: sort3
LANG: C++14
*/

// solved 2020-08-06

#include <iostream>
#include <fstream>
#include <memory>
#define MAXN 1000
using namespace std;

int x[MAXN + 5], cnt[4], should[MAXN + 5];

int main()
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    int n;
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        fin >> x[i];
        cnt[x[i]]++;
    }

    for (int i = 1; i <= cnt[1]; i++)
        should[i] = 1;
    for (int i = cnt[1] + 1; i <= cnt[1] + cnt[2]; i++)
        should[i] = 2;
    for (int i = cnt[1] + cnt[2] + 1; i <= n; i++)
        should[i] = 3;

    int total = 0;
    for (int p = 1; p <= n - 1; p++)
        for (int q = p + 1; q <= n; q++)
            if (x[p] != should[p] && x[q] != should[q] && x[p] == should[q] && x[q] == should[p])
                total++, swap(x[p], x[q]);
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (x[i] != should[i])
            k++;

    fout << total + k * 2 / 3 << '\n';

    fin.close();
    fout.close();
    return 0;
}
