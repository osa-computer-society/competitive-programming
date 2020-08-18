/*
ID: a.cai61
TASK: castle
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <cstring>
#define MAXN 52
using namespace std;

int walls[MAXN][MAXN], num[MAXN][MAXN], roomsize[MAXN*MAXN];
int nc, nr;
const int west = 1, north = 2, east = 4, south = 8;

void number(int i, int r, int c)
{
    if (num[r][c] != -1) return;
    num[r][c] = i;
    roomsize[i]++;
    int &wall = walls[r][c];
    if (r > 1 && !(wall & north)) number(i, r-1, c);
    if (r < nr && !(wall & south)) number(i, r+1, c);
    if (c > 1 && !(wall & west)) number(i, r, c-1);
    if (c < nc && !(wall & east)) number(i, r, c+1);
}

int main()
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");

    fin >> nc >> nr;
    for (int i = 1; i <= nr; i++)
        for (int j = 1; j <= nc; j++)
            fin >> walls[i][j];

    int nrooms = 0;
    memset(num, -1, sizeof(num));
    for (int i = 1; i <= nr; i++)
        for (int j = 1; j <= nc; j++)
            if (num[i][j] == -1)
                number(nrooms++, i, j);
    
    fout << nrooms << '\n';
    int maxroom = -1;
    for (int i = 0; i < nrooms; i++)
        if (roomsize[i] > maxroom) maxroom = roomsize[i];
    fout << maxroom << '\n';

    int wr = -1, wc = -1, maxtwo = -1;
    char dir;
    for (int c = 1; c <= nc; c++)
    {
        for (int r = nr; r >= 1; r--)
        {
            if (r > 1 && (walls[r][c] & north))
            {
                int a = num[r][c], b = num[r-1][c];
                int t = roomsize[a] + roomsize[b];
                if (a != b && t > maxtwo)
                    maxtwo = t, wr = r, wc = c, dir = 'N';
            }
            if (c < nc && (walls[r][c] & east))
            {
                int a = num[r][c], b = num[r][c+1];
                int t = roomsize[a] + roomsize[b];
                if (a != b && t > maxtwo)
                    maxtwo = t, wr = r, wc = c, dir = 'E';
            }
        }
    }

    fout << maxtwo << '\n';
    fout << wr << ' ' << wc << ' ' << dir << '\n';

    fin.close();
    fout.close();
    return 0;
}
