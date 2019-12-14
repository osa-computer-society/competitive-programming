// Problem ID: ccc09s5
// By Alexander Cai

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int diff[1005][30005];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int M, N, K, x, y, r, b, t1, t2;
  double k;
  cin >> M >> N >> K;

  for (int i = 0; i < K; i++)
  {
    cin >> x >> y >> r >> b;
    // cout << "x, y, r, b: " << x << ", " << y << ", " << r << ", " << b << endl;
    for (int col = max(1, x-r); col <= x + r && col <= N; col++)
    {
      // cout << "\tcol: " << col << "; t1, t2: ";
      k = sqrt(r*r - pow(col-x, 2));
      t1 = max(ceil(y - k), 1.);
      t2 = min(floor(y + k), (double) M);
      diff[col][t1] += b;
      diff[col][t2+1] -= b;
      // cout << t1 << ", " << t2 << endl;
    }
    // cout << "\n\n";
    // for (int j = 1; j < M+1; j++)
    // {
    //   for (int k = 1; k < N+1; k++)
    //     cout << diff[k][j] << " ";
    //   cout << "\n";
    // }
  }

  int ans = 0, nans = 0;
  for (int col = 1; col <= N; col++)
  {
    // cout << "col " << col << "\n";
    int total = 0;
    for (int row = 1; row <= M; row++)
    {
      total += diff[col][row];
      // cout << total << " ";
      if (total > ans)
      {
        ans = total;
        nans = 1;
      }
      else if (total == ans) nans++;
      // cout << ans << " " << nans << "\n";
    }
  }

  cout << ans << "\n" << nans;

  return 0;
}
