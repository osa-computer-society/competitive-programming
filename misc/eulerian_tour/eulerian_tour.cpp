// Problem ID:
// By Alexander Cai

#include <iostream>
#include <vector>
#define MAXN 105
using namespace std;

vector<int> adj[MAXN];
vector<int> circuit; // the order in which the vertices will be traversed

void find_circuit(int u)
{
    for (int v = adj[v].size()-1; v >= 0; --v)
    {
        adj[u].pop_back();
        for (int k = 0; k < adj[v].size(); ++k)
        {
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    int u, v;
    for (int i = 1; i <= V; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
