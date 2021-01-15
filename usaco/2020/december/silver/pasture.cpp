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

int diff[MAXN][MAXN];

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    cin >> pos[i].f >> pos[i].s;
  }

  sort(pos + 1, pos + N + 1);

  for (int i = 1; i <= N; ++i)
  {
    pos[i].f = i;
    diff[pos[i].f][pos[i].s]++;
  }

  ll total = 1 << N;

  for (int c1 = 2; c1 <= N - 1; ++c1)
  {
    for (int c2 = 1; c2 <= c1 - 1; ++c2)
    {
      for (int c3 = c1 + 1; c3 <= N; ++c3)
      {
        cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
        pii cow1 = pos[c1], cow2 = pos[c2], cow3 = pos[c3];
        if ((cow1.s > cow2.s && cow1.s < cow3.s) ||
            (cow1.s < cow2.s && cow1.s > cow3.s))
          total -= 1 + (c2 - c1 - 1), cout << "DEAD\n";
      }
    }
  }

  cout << total << '\n';

  return 0;
}