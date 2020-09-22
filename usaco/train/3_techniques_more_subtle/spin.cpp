/*
ID: a.cai61
TASK: spin
LANG: C++14
*/

// solved 2020-09-21

// simple brute force, implementation

#include <iostream>
#include <fstream>
#include <cstring>
#define FOR(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");

struct wheel
{
    int speed;
    int numwedges;
    int start[6];
    int extent[6];
};

wheel wheels[6];

int main()
{
    FOR(i, 5)
    {
        fin >> wheels[i].speed >> wheels[i].numwedges;
        FOR(j, wheels[i].numwedges)
            fin >> wheels[i].start[j] >> wheels[i].extent[j];
    }

    int mask[360];
    int ans = -1;
    for (int ang = 0; ang < 360; ++ang)
    {
        memset(mask, 0, sizeof(mask));
        FOR(i, 5)
            FOR(j, wheels[i].numwedges)
                for (int t = wheels[i].start[j], c = 0; c <= wheels[i].extent[j]; t = (t + 1) % 360, ++c)
                    mask[t] |= 1 << i;
        
        // for each angle, see if light can pass through all the wedges
        for (int a = 0; a < 360; ++a)
            if (mask[a] == (1 << 6) - 2)
                ans = ang;

        if (ans != -1)
            break;
        
        FOR(i, 5)
            FOR(j, wheels[i].numwedges)
                wheels[i].start[j] = (wheels[i].start[j] + wheels[i].speed) % 360;
    }

    if (ans == -1)
        fout << "none\n";
    else
        fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
