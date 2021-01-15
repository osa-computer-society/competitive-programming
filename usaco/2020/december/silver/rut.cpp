// solved

#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
using namespace std;
const int MAXN = 1005;

using piii = pair<pair<int, int>, int>;

vector<piii> ns, es;

int stops[MAXN];
bool stopped[MAXN];

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'E')
      es.push_back({{a, b}, i});
    else
      ns.push_back({{a, b}, i});
  }
  sort(ns.begin(), ns.end());

  for (piii n : ns)
  {
    if (stopped[n.s])
      continue;
    piii search = {{n.f.f, 0}, 0};
    sort(es.begin(), es.end());
    auto it = lower_bound(es.begin(), es.end(), search);
    sort(es.begin(), it, [](const piii &l, const piii &r) {
      return l.f.s < r.f.s;
    });

    for (auto i = es.begin(); i != it; ++i)
    {
      piii e = *i;
      if (n.f.s > e.f.s || stopped[e.s])
        continue;
      int tn = e.f.s - n.f.s;
      int te = n.f.f - e.f.f;
      // cout << n.s << " N vs E " << e.s << " (tn, te): " << tn << ' ' << te << '\n';
      if (tn < te)
      {
        stops[n.s] += stops[e.s] + 1;
        stopped[e.s] = true;
        // cout << "stops[n.s] = " << stops[n.s] << '\n';
      }
      else if (te < tn)
      {
        stops[e.s] += stops[n.s] + 1;
        stopped[n.s] = true;
        // cout << "stops[e.s] = " << stops[e.s] << '\n';
        break;
      }
    }
    sort(es.begin(), it);
  }

  for (int i = 1; i <= N; ++i)
  {
    cout << stops[i] << '\n';
  }

  return 0;
}
