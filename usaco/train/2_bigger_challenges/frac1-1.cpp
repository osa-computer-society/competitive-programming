/*
ID: a.cai61
TASK: frac1
LANG: C++14
*/

// Solved 2020-08-06

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 160
using namespace std;

typedef pair<int, int> pii;

pii valid[MAXN * MAXN + 2];

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    int n;
    fin >> n;

    int cnt = 0;
    for (int lo = 1; lo <= n; lo++)
        for (int hi = 0; hi <= lo; hi++)
            if (gcd(lo, hi) == 1)
                valid[cnt++] = make_pair(hi, lo);

    sort(valid, valid + cnt, [](const pii &a, const pii &b) {
        return a.first * b.second < b.first * a.second;
    });

    for (int i = 0; i < cnt; i++)
        fout << valid[i].first << '/' << valid[i].second << '\n';

    fin.close();
    fout.close();
    return 0;
}
