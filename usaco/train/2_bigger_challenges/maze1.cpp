/*
ID: a.cai61
TASK: maze1
LANG: C++14
*/

// solved 2020-08-26

// maze, recursion

#include <iostream>
#include <fstream>
#include <cstring>
#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8
#define MAXNR 105
#define MAXNC 40
using namespace std;

int NC, NR, walls[MAXNR][MAXNC], dist[MAXNR][MAXNC];

ifstream fin("maze1.in");
ofstream fout("maze1.out");

void rec(int r, int c, int i)
{
    if (r < 1 || r > NR || c < 1 || c > NC || dist[r][c] <= i)
        return;
    dist[r][c] = i;
    if (!(walls[r][c] & NORTH))
        rec(r - 1, c, i + 1);
    if (!(walls[r][c] & EAST))
        rec(r, c + 1, i + 1);
    if (!(walls[r][c] & SOUTH))
        rec(r + 1, c, i + 1);
    if (!(walls[r][c] & WEST))
        rec(r, c - 1, i + 1);
}

int main()
{
    memset(dist, 0x3f, sizeof(dist));

    fin >> NC >> NR;
    fin.get();
    int exitr[2], exitc[2];
    char t;
    int cnt = 0;
    for (int r = 1; r <= 2 * NR + 1; ++r)
    {
        int rr = (r + 1) / 2;
        if (r & 1)
        {
            for (int c = 2; c <= 2 * NC; c += 2)
            {
                fin.get();
                t = fin.get();
                int cc = c / 2; // col of block to south
                if (t == '-')
                {
                    walls[rr][cc] |= NORTH;
                    if (rr > 1)
                        walls[rr - 1][cc] |= SOUTH;
                }
                else if (rr == 1) // exit
                    exitr[cnt] = rr, exitc[cnt] = cc, ++cnt;
                else if (rr == NR + 1)
                    exitr[cnt] = rr - 1, exitc[cnt] = cc, ++cnt;
            }
            fin.get(); // last '+'
        }
        else // even row, vertical columns
        {
            for (int c = 1; c <= 2 * NC + 1; c += 2)
            {
                if (c > 1)
                    fin.get(); // ' '
                t = fin.get();
                int cc = (c + 1) / 2; // col of block to east
                if (t == '|')
                {
                    if (cc <= NC)
                        walls[rr][cc] |= WEST;
                    if (cc > 1)
                        walls[rr][cc - 1] |= EAST;
                }
                else if (cc == 1)
                    exitr[cnt] = rr, exitc[cnt] = cc, ++cnt;
                else if (cc == NC + 1)
                    exitr[cnt] = rr, exitc[cnt] = cc - 1, ++cnt;
            }
        }
        if (r < 2 * NR + 1)
            fin.get(); // newline
    }

    rec(exitr[0], exitc[0], 1);
    rec(exitr[1], exitc[1], 1);

    int ans = -1;
    for (int r = 1; r <= NR; ++r)
        for (int c = 1; c <= NC; ++c)
            ans = max(ans, dist[r][c]);

    fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
