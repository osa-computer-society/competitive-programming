// CCC '15 S4 - Convex Hull
// By 

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 0x3f3f3f3f
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

// a - distance
// b - damage
// c - target
typedef tuple<int,int,int> edge;

struct node
{
  // i - index
  // p - parent
  // d - distance
  // k - remaining health
  int i, p, d, k;
  vector<edge> adj;
};

// k - thickness of ship's hull
// n - num vertices
// m - num edges
int k, n, m, i, a, b, t, h, A, B, u, v, tt, hh, vv;
vector<node> V;

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> n >> m;

  for (i = 0; i < n; ++i)
  {
    node u;
    u.i = i;
    V.push_back(u);
  }

  // Read in edges
  for (i = 0; i < m; ++i)
  {
    cin >> a >> b >> t >> h;
    V[a].adj.push_back(make_tuple(b, t, h));
    V[b].adj.push_back(make_tuple(a, t, h));
  }

  // A - start
  // B - finish
  cin >> A >> B;

  // Initialize single source
  for (node &v : V)
  {
    v.d = INF;
    v.p = -1;
    v.k = INF;
  }
  node &s = V[A];
  s.d = 0;
  s.k = k; // starting health

  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(make_tuple(0, 0, A));
  while (!Q.empty())
  {
    tie(t, h, u) = Q.top(); Q.pop();
    for (edge e : V[u].adj)
    {
      tie(tt, hh, vv) = e;
      node &vv
      if (V[v].d > V[u].d + tt)
      {

      }
    }
  }


  return 0;
}
