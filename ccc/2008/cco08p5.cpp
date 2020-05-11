// Problem ID: cco08p5.cpp
// By 

#include <iostream>
#include <cstring>
#define MAXN 105
#define MAXK 5000005
using namespace std;

int k[MAXN], c[MAXN], cnt[MAXK];
bool dp[MAXK];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int total = 0;
    for (int i = 1; i <= N; i++)
    {
      cin >> k[i] >> c[i];
      total += k[i] * c[i];
    }

    int K = total / 2;
    int maxcal = 0;

    dp[0] = true;
    for (int i = 1; i <= N; i++)
    {
      memset(cnt, 0, sizeof cnt);
      for (int j = c[i]; j <= K; j++)
      {
        if (dp[j-c[i]] && cnt[j-c[i]] < k[i] && !dp[j])
        {
          dp[j] = true;
          cnt[j] = cnt[j-c[i]] + 1;
          maxcal = max(maxcal, j);
        }
      }
    }

    cout << abs(total - maxcal * 2) << '\n';

    return 0;
}
