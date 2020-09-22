/*
ID: a.cai61
TASK: fact4
LANG: C++14
*/

// solved 2020-09-20

#include <iostream>
#include <fstream>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

int main()
{
    int N;
    fin >> N;

    int prod = 1;
    FOR(i, N)
    {
        prod = (prod * i) % 1000000; // keep right 6 digits since N goes up to 4220 (bit of a hack)
        while (prod % 10 == 0)
            prod /= 10;
    }

    fout << prod % 10 << '\n';

    fin.close();
    fout.close();
    return 0;
}
