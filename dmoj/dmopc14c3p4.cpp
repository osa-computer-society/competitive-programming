// Problem ID: dmopc14c3p4
// By Alexander Cai 14 Dec 2019
// Solved

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int fac[100005];
vector<int> factors[100005];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 100001; i++)
  {
    for (int j = i; j <= 100001; j += i) fac[j]++;
    factors[fac[i]].push_back(i);
  }

  int T, K, A, B;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> K >> A >> B;
    if (factors[K].empty() || *factors[K].rbegin() < A) cout << 0 << "\n";
    else
    {
      auto it1 = lower_bound(factors[K].begin(), factors[K].end(), A);
      auto it2 = prev(upper_bound(factors[K].begin(), factors[K].end(), B));
      cout << it2 - it1 + 1 << "\n";
    }
  }

  return 0;
}
