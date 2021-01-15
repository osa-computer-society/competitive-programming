#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int MAXN = 2505;

pii pos[MAXN];
bool adj[MAXN][MAXN];
ll cnt[MAXN];

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    cin >> pos[i].f >> pos[i].s;
  }

  sort(pos + 1, pos + N + 1);

  for (int a = 1; a <= N - 1; ++a)
  {
    pii pa = pos[a];
    for (int b = a + 1; b <= N; ++b)
    {
      pii pb = pos[b];
      adj[a][b] = adj[b][a] = true;
      for (int c = a + 1; c <= b - 1; ++c)
      {
        pii pc = pos[c];
        if ((pa.s > pc.s && pc.s > pb.s) || (pa.s < pc.s && pc.s < pb.s))
        {
          adj[a][b] = adj[b][a] = false;
          break;
        }
      }
    }
  }

  for (int a = 1; a <= N; ++a)
  {
    for (int b = 1; b <= N; ++b)
    {
      cout << adj[a][b] << ' ';
    }
    cout << '\n';
  }

  ll total = 1; // empty set

  for (int a = 1; a <= N; ++a)
  {
    cnt[a] = 1;
    for (int b = 1; b <= a - 1; ++b)
    {
      if (adj[a][b])
        cnt[a] += cnt[b];
    }
    total += cnt[a];
    // cout << "cnt[" << a << "]: " << cnt[a] << '\n';
  }

  cout << total << '\n';

  return 0;
}