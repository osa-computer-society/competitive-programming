// Problem ID: treepractice1
// By Alexander Cai 18 Dec 2019
// Solved

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#define MAXN 500000

using namespace std;

typedef pair<int, int> pii;

const int INF = std::numeric_limits<int>::max();

int N, a, b, w, u, v, end1, end2, d;
vector<pii> adj[MAXN];
int dist[MAXN];
int par[MAXN];
int vis[MAXN];

pii bfs(int s)
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
        dist[i] = INF;
        par[i] = -1;
    }
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        u = Q.front(); Q.pop();
        for (pii p : adj[u])
        {
            if (vis[p.first] == 0)
            {
                vis[p.first] = 1;
                par[p.first] = u;
                dist[p.first] = dist[u] + p.second;
                Q.push(p.first);
            }
        }
        vis[u] = 2;
    }

    int j = 0, max_d = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > max_d)
        {
            max_d = dist[i];
            j = i;
        }
    }
    return make_pair(j, max_d);
}

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N-1; i++)
  {
      cin >> a >> b >> w;
      adj[a-1].push_back(make_pair(b-1, w));
      adj[b-1].push_back(make_pair(a-1, w));
  }

  tie(end1, d) = bfs(0);
  tie(end2, d) = bfs(end1);
  int rad = INF;
  int p = par[end2];
  while (p != end1)
  {
      int t = max(dist[p], d - dist[p]);
      if (t < rad) rad = t;
      p = par[p];
  }
  
  cout << d << "\n" << rad << endl;

  return 0;
}
