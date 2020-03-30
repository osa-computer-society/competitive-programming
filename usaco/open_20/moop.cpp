// Problem ID: oly18novp8
// By Alexander Cai
// Keywords: Binary Indexed Tree, Fenwick Tree, Data Structures

#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#define MAXN 15005
#define MAXX 32005
using namespace std;
typedef pair<int,int> pii;

int N, freq[MAXX], lvl[MAXN], par[MAXN], rk[MAXN];
set<int> pars;

pii graph[MAXN];

int find_set(int u)
{
    if (u != par[u])
        par[u] = find_set(par[u]);
    return par[u];
}

void link(int u, int v)
{
    u = find_set(u), v = find_set(v);
    if (rk[u] < rk[v]) par[u] = v;
    else
    {
        par[v] = u;
        if (rk[v] == rk[u]) rk[u]++;
    }
}

int main()
{
    ifstream fin("moop.in");
    ofstream fout("moop.out");

    fin >> N;
    for (int i = 1; i <= N; i++)
    {
        par[i] = i, rk[i] = 0;
        fin >> graph[i].first >> graph[i].second;
    }

    sort(graph + 1, graph + N+1, less<pii>());

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (graph[j].first <= graph[i].first && graph[j].second <= graph[i].second)
                link(i, j);
        }
    }

    for (int i = 1; i <= N; i++) pars.insert(find_set(i));

    fout << pars.size() << '\n';

    return 0;
}
