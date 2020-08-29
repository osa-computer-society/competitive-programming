/*
ID: a.cai61
TASK: ttwo
LANG: C++14
*/

// solved 2020-08-26

// simulation

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char grid[11][11];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

void move(int *r, int *c, int *dir)
{
    int nr = *r + dr[*dir];
    int nc = *c + dc[*dir];
    if (nr < 1 || nr > 10 || nc < 1 || nc > 10 || grid[nr][nc] == '*')
        *dir = (*dir + 1) % 4;
    else
        *r = nr, *c = nc;
}

int main()
{
    int cowr, cowc, cowdir = 0, farmr, farmc, farmdir = 0;
    for (int r = 1; r <= 10; ++r)
        for (int c = 1; c <= 10; ++c)
        {
            fin >> grid[r][c];
            if (grid[r][c] == 'C')
                cowr = r, cowc = c, grid[r][c] = '.';
            else if (grid[r][c] == 'F')
                farmr = r, farmc = c, grid[r][c] = '.';
        }
    
    int i;
    for (i = 0; i < 400*400 && !(cowr == farmr && cowc == farmc); ++i)
    {
        move(&cowr, &cowc, &cowdir);
        move(&farmr, &farmc, &farmdir);
    }

    if (i == 400 * 400)
        fout << 0 << '\n';
    else
        fout << i << '\n';

    fin.close();
    fout.close();
    return 0;
}
