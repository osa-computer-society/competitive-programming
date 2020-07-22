/*
ID: a.cai61
TASK: transform
LANG: C++14
*/

// solved 2020-07-19

#include <iostream>
#include <fstream>
#define GRID_SIZE 12
using namespace std;
typedef bool grid[GRID_SIZE][GRID_SIZE];

void read_grid(ifstream* fin, int N, grid g)
{
    char ch;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            *fin >> ch;
            g[r][c] = ch == '@';
        }
    }
}

int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    grid g1, g2;
    int N;
    fin >> N;

    read_grid(&fin, N, g1);
    read_grid(&fin, N, g2);

    bool valid[10];
    for (int i = 1; i <= 9; i++) valid[i] = true;
    valid[5] = false;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
        {
            if (g1[r][c] != g2[c][N-r-1]) // cw rot
                valid[1] = false;
            if (g1[r][c] != g2[N-r-1][N-c-1]) // 180 rot
                valid[2] = false;
            if (g1[r][c] != g2[N-c-1][r]) // ccw rot
                valid[3] = false;
            if (g1[r][c] != g2[r][N-c-1]) // hor ref
                valid[4] = false;
            if (g1[r][c] != g2[r][c]) // no change
                valid[6] = false;

            if (g1[r][c] != g2[N-c-1][N-r-1]) // flip then cw
                valid[7] = false;
            if (g1[r][c] != g2[N-r-1][c]) // flip then 180
                valid[8] = false;
            if (g1[r][c] != g2[c][r]) // flip then ccw
                valid[9] = false;
        }

    if (valid[7] || valid[8] || valid[9])
        valid[5] = true;

    int ans = -1;
    for (int i = 1; i <= 8; i++)
        if (valid[i])
        {
            ans = i; break;
        }
    if (ans == -1) fout << 7 << '\n';
    else fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
