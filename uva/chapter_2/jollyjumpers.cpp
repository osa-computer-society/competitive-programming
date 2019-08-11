// Problem ID: 10038
// By Alexander Cai 2019-06-14
// Accepted


#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int main() {
  int n, m, prev;

  while (cin >> n) {
    bool jolly = true;
    // Main idea: we use a set to keep track of the unique absolute differences
    // between consecutive numbers
    set<int> checker;

    // Read the input, we get the first one to be prev so we loop 1 less time
    cin >> prev;
    for (int i = 0; i < n - 1; i++) {
      cin >> m;
      checker.insert(abs(m - prev));
      prev = m;
    }

    // If any of the following are false, it's not jolly
    cout << ((
      checker.size() == n - 1
      && checker.count(0) <= 0
      && checker.upper_bound(n-1) == checker.end())
      ? "Jolly"
      : "Not jolly")
      << endl;
  }
  return 0;
}
