/*
ID: a.cai61
TASK: fence
LANG: C++14
*/

// solved 2020-09-22

// make sure to remember multiple paths between vertices: used adj matrix for this
// eulerian circuit, graph

#include <iostream>
#include <fstream>
#include <vector>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXN 505
using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");

vector<int> circuit;
int adj[MAXN][MAXN]; // adjacency matrix for easy edge removal
int deg[MAXN];

void find_circuit(int u)
{
    cout << u << '\n';
    // for adjacent vertices in increasing order, recursively find circuit
    FOR(v, 500)
        if (adj[u][v])
        {
            --adj[u][v];
            --adj[v][u];
            find_circuit(v);
        }
    circuit.push_back(u);
}

int main()
{
    int V = -1, E;
    fin >> E;
    int u, v;
    FOR(i, E)
    {
        fin >> u >> v;
        ++adj[u][v];
        ++adj[v][u];
        ++deg[u], ++deg[v];
        V = max(V, max(u, v));
    }

    int st; // vertex to start at
    for (st = 1; st <= V; ++st)
        if (deg[st] & 1)
            break;
    
    // if no vertices with odd degree, go with the first
    find_circuit(st > V ? 1 : st);

    for (int i = circuit.size() - 1; i >= 0; --i)
        fout << circuit[i] << '\n';

    fin.close();
    fout.close();
    return 0;
}
