/*
ID: a.cai61
TASK: lamps
LANG: C++14
*/

// Solved 2020-08-19

#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#define MODSIX(x) (((x)+5)%6+1)
using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");

int N, C;
int oglamps[7];
set<int> valid;

int buttons[] = {
    0b111111,
    0b101010,
    0b010101,
    0b100100,
};

void recurse(int k, int c, int lamps)
{
    if (c > C) return;

    if (k == 4)
    {
        bool done = true;
        for (int j = 1; j <= 6; j++)
        {
            int d = (lamps & (1 << (6-j))) >> (6-j);
            if (oglamps[j] != -1 && d != oglamps[j])
                done = false;
        }
        if (done)
            valid.insert(lamps);
        return;
    }

    recurse(k+1, c, lamps);
    recurse(k+1, c+1, lamps ^ buttons[k]);
}

int main()
{
    fin >> N >> C;
    memset(oglamps, -1, sizeof(oglamps));
    int k;
    while (fin >> k, k != -1)
        oglamps[MODSIX(k)] = 1;
    while (fin >> k, k != -1)
    {
        int &l = oglamps[MODSIX(k)];
        if (l == 1)
        {
            fout << "IMPOSSIBLE\n";
            fin.close();
            fout.close();
            return 0;
        }
        l = 0;
    }

    recurse(0, 0, 0b111111);

    if (valid.size() == 0)
    {
        fout << "IMPOSSIBLE\n";
        fin.close();
        fout.close();
        return 0;
    }

    for (set<int>::iterator it = valid.begin(); it != valid.end(); it++)
    {
        for (int i = 1; i <= N; i++)
            fout << (((*it) & (1 << (6-MODSIX(i)))) >> (6-MODSIX(i)));
        fout << '\n';
    }
    
    fin.close();
    fout.close();
    return 0;
}
