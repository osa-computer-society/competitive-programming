#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2505;

pii pos[MAXN];

int diff1[MAXN][MAXN];
int diff2[MAXN][MAXN];

bool adj[MAXN][MAXN];

int main()
{
  int N;
  cin >> N;

  int maxx = -1;

  for (int i = 1; i <= N; ++i)
  {
    cin >> pos[i].f >> pos[i].s;
  }

  sort(pos + 1, pos + N + 1, [](const pii &l, const pii &r) {
    return l.s < r.s;
  });

  for (int i = 1; i <= N; ++i)
  {
    pos[i].s = i;
  }

  sort(pos + 1, pos + N + 1);

  for (int i = 1; i <= N; ++i)
  {
    pos[i].f = i;
    diff1[i][pos[i].s]++;
    diff2[i][pos[i].s]++;
  }

  // for (int i = 1; i <= N; ++i)
  // {
  //   cout << pos[i].f << ' ' << pos[i].s << '\n';
  // }

  for (int x = 1; x <= N; ++x)
  {
    for (int y = 1; y <= N; ++y)
    {
      diff1[x][y] += diff1[x][y - 1];
    }
    for (int y = N; y >= 1; --y)
    {
      diff2[x][y] += diff2[x][y + 1];
    }
    for (int y = 1; y <= N; ++y)
    {
      diff1[x][y] += diff1[x - 1][y];
      diff2[x][y] += diff2[x - 1][y];
    }
  }

  // cout << '\n';
  // for (int y = N; y >= 1; --y)
  // {
  //   for (int x = 1; x <= N; ++x)
  //   {
  //     cout << diff1[x][y] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';
  // for (int y = N; y >= 1; --y)
  // {
  //   for (int x = 1; x <= N; ++x)
  //   {
  //     cout << diff2[x][y] << ' ';
  //   }
  //   cout << '\n';
  // }

  ll total = 0;

  cout << total << '\n';

  return 0;
}