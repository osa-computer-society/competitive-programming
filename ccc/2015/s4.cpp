// CCC '15 S4 - Convex Hull
// By Alexander Cai
// Solved 5 Jan 2020

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 2005
#define MAXK 205
using namespace std;

struct edge
{
  int v, t, h;
  edge(int v, int t, int h) : v(v), t(t), h(h) {}
};

vector<edge> adj[MAXN];
int dist[MAXN][MAXK];
bool vis[MAXN][MAXK];

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  int K, N, M, a, b, t, h;
  cin >> K >> N >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> a >> b >> t >> h;
    adj[a].push_back(edge(b, t, h));
    adj[b].push_back(edge(a, t, h));
  }

  int A, B;
  cin >> A >> B;

  for (int i = 1; i <= N; i++)
    for (int k = 0; k <= K; k++)
      dist[i][k] = INF;
  dist[A][K] = 0;

  auto compare = [](edge l, edge r)
  {
    return l.t > r.t;
  };

  priority_queue<edge, vector<edge>, decltype(compare)> Q(compare);
  Q.push(edge(A, 0, K));
  int min_time = INF;
  while (!Q.empty())
  {
    edge e = Q.top(); Q.pop();
    if (e.v == B)
    {
      min_time = e.t;
      break;
    }
    if (vis[e.v][e.h]) continue;
    vis[e.v][e.h] = 1;
    for (edge f : adj[e.v])
    {
      t = dist[e.v][e.h] + f.t;
      h = e.h - f.h;
      if (h > 0)
      {
        if (t < dist[f.v][h])
          dist[f.v][h] = t;
        Q.push(edge(f.v, t, h));
      }
    }
  }

  if (min_time == INF) min_time = -1;
  cout << min_time << '\n';

  return 0;
}
