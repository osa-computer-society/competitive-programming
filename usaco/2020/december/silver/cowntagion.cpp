// solved

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
bool vis[MAXN];
int deg[MAXN];
int total_dist = 0;

void dfs(int u)
{
  vis[u] = 1;
  if (deg[u] == 1)
    return;

  total_dist += ceil(log2(deg[u]));

  for (int v : adj[u])
  {
    if (!vis[v])
    {
      total_dist += 1;
      dfs(v);
    }
  }
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N - 1; ++i)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }

  deg[1]++; // hack
  dfs(1);

  // num splits
  cout << total_dist << '\n';

  return 0;
}
