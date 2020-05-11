// Problem ID: dmopc18c4p2.cpp
// By 

#include <iostream>
#define MAXN 705
#define MAXV 700*700+5
using namespace std;

int a[MAXN];
bool dp[2][MAXV];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, total = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i], total += a[i];
    int W = total / 2;

    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= N; i++)
    {
      int curr = i%2, prev = (i+1)%2;
      for (int j = a[i]; j <= W; j++)
        dp[curr][j] |= dp[prev][j] | dp[prev][j-a[i]];
    }

    for (int i = W; i >= 0; i--)
    {
      if (dp[N%2][i])
      {
        cout << total - 2*i << '\n';
        break;
      }
    }

    return 0;
}
