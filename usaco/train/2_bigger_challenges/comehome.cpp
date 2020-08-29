/*
ID: a.cai61
TASK: comehome
LANG: C++14
*/

// solved 2020-08-28

// Floyd-Warshall

#include <iostream>
#include <fstream>
#include <cstring>
#define MAXN 100
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

int P; // # pastures
int dist[MAXN][MAXN];

ifstream fin("comehome.in");
ofstream fout("comehome.out");

int ctoi(char c)
{
    if ('A' <= c && c <= 'Z') return c - 'A'+1;
    else return c - 'a' + 26+1;
}

int main()
{
    fin >> P;

    int N = 52;

    memset(dist, 0x3f, sizeof(dist));
    FOR(i, N) dist[i][i] = 0;

    char u, v, uu, vv;
    int d;
    FOR(i, P)
    {
        fin >> uu >> vv >> d;
        int u = ctoi(uu), v = ctoi(vv);
        dist[u][v] = dist[v][u] = min(dist[u][v], d);
    }

    FOR(k, N) FOR(i, N) FOR(j, N)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    char cow;
    int ans = 0x3f3f3f3f;
    for (char c = 'A'; c <= 'Y'; ++c)
    {
        int d = dist[ctoi(c)][ctoi('Z')];
        if (d < ans)
            cow = c, ans = d;
    }
    
    fout << cow << ' ' << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
