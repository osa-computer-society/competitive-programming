/*
ID: a.cai61
TASK: cowtour
LANG: C++14
*/

// solved 2020-08-28

// graph traversal, connected components, embedded graph

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <math.h>
#define MAXN 155
#define INF 1e40
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

int N;
int x[MAXN], y[MAXN];
bool adj[MAXN][MAXN];
double dist[MAXN][MAXN];
double diam[MAXN];
double field_diam[MAXN];
int tree[MAXN];

double distance(int i, int j)
{
    return sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
}

void mark(int u, int x)
{
    // ignore if it has already been set
    if (tree[u] != -1)
        return;
    tree[u] = x;
    // mark all adjacent vertices
    FOR(i, N)
        if (adj[u][i])
            mark(i, x);
}

int main()
{
    fin >> N;

    // read coordinates of pastures
    FOR(i, N)
        fin >> x[i] >> y[i];

    // read adjacency matrix
    char t;
    FOR(i, N) FOR(j, N)
    {
        fin >> t;
        adj[i][j] = t - '0';
        if (i == j)
            dist[i][j] = 0;
        else if (adj[i][j])
            dist[i][j] = distance(i, j);
        else
            dist[i][j] = INF;
    }
    
    // mark fields
    memset(tree, -1, sizeof(tree));
    int ntrees = 0;
    FOR(i, N)
        if (tree[i] == -1)
            mark(i, ++ntrees);
    
    // Floyd-Warshall shortest pairs in each tree
    FOR(k, N) FOR(i, N) FOR(j, N)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    FOR(i, N)
    {
        // calculate max distance among adjacent vertices
        FOR(j, N)
            if (tree[i] == tree[j])
                diam[i] = max(diam[i], dist[i][j]);
        field_diam[tree[i]] = max(field_diam[tree[i]], diam[i]);
        // cout << tree[i] << ' ' << diam[i] << ' ' << field_diam[tree[i]] << '\n';
    }

    double ans = INF;
    FOR(i, N) FOR(j, N)
        if (tree[i] != tree[j])
            ans = min(ans, max(diam[i] + distance(i, j) + diam[j], max(field_diam[tree[i]], field_diam[tree[j]])));

    fout << fixed << setprecision(6) << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
