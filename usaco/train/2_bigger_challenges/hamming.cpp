// solved 2020-08-06

#include <iostream>
#include <fstream>
#define MAXN 64
#define MAXB 8
#define MAXVAL (1 << MAXB)
using namespace std;

int N, B, D, arr[MAXN+5], dist[MAXVAL+5][MAXVAL+5];
int maxval;
bool done = false;

ifstream fin("hamming.in");
ofstream fout("hamming.out");

void recurse(int n, int k)
{
    if (n == N)
    {
        for (int i = 0; i < N; i++)
        {
            if (i % 10) fout << ' ';
            fout << arr[i];
            if (i % 10 == 9 || i == N-1) fout << '\n';
        }

        fin.close();
        fout.close();
        exit(0);
    }
    for (int i = k; i < maxval; i++)
    {
        bool works = true;
        for (int j = 0; j < n; j++)
            if (dist[arr[j]][i] < D)
            {
                works = false; break;
            }
        if (works)
        {
            arr[n] = i;
            recurse(n+1, k+1);
        }
    }
}

int main()
{
    fin >> N >> B >> D;

    maxval = 1 << B;
    for (int i = 0; i <= maxval-2; i++)
        for (int j = i+1; j <= maxval-1; j++)
            for (int k = 0; k < B; k++)
                if ((i ^ j) & (1 << k))
                    dist[i][j]++, dist[j][i]++;

    recurse(0, 0);
    return 0;
}
