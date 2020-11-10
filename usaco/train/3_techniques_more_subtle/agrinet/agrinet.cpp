// solved 2020-09-08

#include <iostream>
#include <fstream>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXN 105
using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

int dist[MAXN][MAXN];
bool in_tree[MAXN];

int main()
{
    int N;
    fin >> N;

    for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c)
            fin >> dist[r][c];
    
    int total = 0;
    in_tree[1] = true;
    for (int i = 1; i < N; ++i) // N-1 times
    {
        int mind = -1, node = 0;
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if ((mind == -1 || dist[u][v] < mind) && dist[u][v] && in_tree[u] && !in_tree[v])
                    mind = dist[u][v], node = v;
        total += mind;
        in_tree[node] = true;
    }

    fout << total << '\n';

    fin.close();
    fout.close();
    return 0;
}
