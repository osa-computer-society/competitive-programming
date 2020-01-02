// Problem ID: 
// By Alexander Cai

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <functional>
#define MAXN 100005
using namespace std;

typedef pair<int,int> pii;

int par[MAXN], dist[MAXN];
vector<pii> adj[MAXN];
int diam, furthest;

void dfs(int u, int p)
{
    par[u] = p;
    if (dist[u] >= diam)
        diam = dist[u], furthest = u;
    for (pii e : adj[u])
        if (e.first != p)
            dist[e.first] = dist[u] + e.second, dfs(e.first, u);
}

int travelTime(int N, int M, int L, int A[], int B[], int C[])
{
    memset(par, -1, sizeof(par));

    for (int i = 0; i < M; i++)
    {
        adj[A[i]].push_back({A[i], C[i]});
        adj[B[i]].push_back({B[i], C[i]});
    }
    
    int tree = 0, max_diam = 0;
    vector<int> rads;
    for (int i = 1; i <= N; i++)
    {
        if (par[i] == -1)
        {
            tree++;
            dist[i] = 0, diam = 0;
            dfs(i, i);
            dist[furthest] = 0, diam = 0;
            dfs(furthest, furthest);
            int rad = diam;
            for (int k = furthest; k != par[k]; k = par[k])
                rad = min(rad, max(diam-dist[k], dist[k]));
            rads.push_back(rad);
            if (diam > max_diam) max_diam = diam;
        }
    }

    sort(rads.begin(), rads.end(), greater<int>());

    if (tree == 1) return max_diam;
    else return max(max_diam, rads[0] + rads[1] + L);
}

