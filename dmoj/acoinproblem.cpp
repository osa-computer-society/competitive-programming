// Problem ID: acoinproblem.cpp
// By 
// Unfinished

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 2005
#define MAXC 10005
#define MAXV 100005
#define INF 0x3f3f3f3f
using namespace std;

struct shop
{
  int c, l, i;
  shop(int c, int l, int i) : c(c), l(l), i(i) {};
};

int dp[MAXC], d[MAXN], ans[MAXV];
vector<shop> shops;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, V;
    cin >> N >> V;

    for (int i = 1; i <= N; i++) cin >> d[i];

    int maxc = -1;
    for (int i = 1, c, l; i <= V; i++)
    {
      cin >> c >> l;
      maxc = max(maxc, c);
      shops.push_back(shop(c, l, i));
    }

    sort(shops.begin(), shops.end(), [](shop a, shop b) { return a.l < b.l; });

    // for (shop s : shops) { cout << s.i << ": " << s.c << " " << s.l << "\n"; }

    for (int j = 1; j <= maxc; j++) dp[j] = INF;
    dp[0] = 0;

    int prevl = 0;

    for (shop s : shops)
    {
      // cout << "SHOP " << s.i << ": " << s.c << " " << s.l << "\n";
      int c = s.c, l = s.l;
      for (int j = prevl+1; j <= l; j++)
      {
        // cout << "LOOPING " << j << '\n';
        for (int k = d[j]; k <= maxc; k++)
        {
          dp[k] = min(dp[k], dp[k-d[j]] + 1);
        }
      }
      if (dp[c] == INF) ans[s.i] = -1;
      else ans[s.i] = dp[c];

      // for (int i = 1; i <= maxc; i++) cout << (dp[i] == INF ? -1 : dp[i]) << ',';
      // cout << '\n';
      prevl = l;
    }

    sort(shops.begin(), shops.end(), [](shop a, shop b) { return a.i < b.i; });
    for (shop s : shops) cout << ans[s.i] << '\n';

    return 0;
}
