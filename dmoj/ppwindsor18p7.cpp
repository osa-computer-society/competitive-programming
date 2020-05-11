// Problem ID: ppwindsor18p7.cpp
// By 

#include <iostream>
#define MAXN 1000
using namespace std;
typedef long long ll;

ll dp[MAXN];

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) dp[i] = -1;
  dp[0] = 0;

  for (int i = 1, v; i <= N; i++)
  {
    cin >> v;
    for (int j = i; j <= N; j++)
    {
      dp[j] = max(max(dp[j], dp[j-1]), dp[j-i] + v);
    }
  }

  cout << dp[N] << '\n';

  return 0;
}
