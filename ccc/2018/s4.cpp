// Problem ID: CCC 2018 S4
// By Alexander Cai 2019-08-26
// FINALLY COMPLETE with help from https://github.com/tomzyzhu/DMOJ-solutions/blob/master/CCC%20'18%20S4%20-%20Balanced%20Trees/in%20C%2B%2B.txt

#include <iostream>
#include <unordered_map>
typedef long long ll;
using namespace std;

unordered_map <int,ll> dp;

ll num_trees(int n) {
  if(n == 1 || n == 2) return 1;
  if (dp.count(n)) return dp[n];

  ll ans = 0; int k = n;
  while (k >= 2) {
    // w is the weight of each subtree, nxt is the next smallest weight of future subtrees
    int w = n/k, nxt = n/(w+1);
    ans += (k-nxt) * num_trees(w);
    k = nxt;
  }
  
  return dp[n] = ans;
}

int main() {
  int n;
  cin >> n;
  cout << num_trees(n) << endl;
}
