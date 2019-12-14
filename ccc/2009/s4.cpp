// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct node
{
  ll d, price;
  vector<pii> adj;
  node() { d = INF; price = INF; }
};

struct cmp
{
  bool operator()(const node& lhs, const node& rhs)
  {
    return lhs.d < rhs.d;
  }
};

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  ll N, T, K, D, x, y, c, z, p;
  cin >> N >> T;

  vector<node> V;
  for (int i = 0; i < N; i++)
  {
    node u;
    V.push_back(u);
  }

  for (int i = 0; i < T; i++)
  {
    cin >> x >> y >> c;
    V[x-1].adj.push_back(make_pair(y-1, c));
    V[y-1].adj.push_back(make_pair(x-1, c));
  }

  cin >> K;

  for (int i = 0; i < K; i++)
  {
    cin >> z >> p;
    V[z-1].price = p;
  }

  cin >> D;
  V[D-1].d = 0;

  priority_queue<node, vector<node>, cmp> Q;
  Q.push(V[D-1]);
  while (!Q.empty())
  {
    node u = Q.top(); Q.pop();
    for (pii i : u.adj)
    {
      if (V[i.first].d > u.d + i.second)
      {
        V[i.first].d = u.d + i.second;
        Q.push(V[i.first]);
      }
    }
  }

  ll ans = INF;
  for (node u : V)
  {
    if (u.d + u.price < ans)
      ans = u.d + u.price;
  }

  cout << ans;

  return 0;
}
