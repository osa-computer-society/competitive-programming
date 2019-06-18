// Problem ID: 10050
// By Alexander Cai 18-06-2019
// Accepted

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n, p, h[100], total;
  cin >> t;
  while (t--) {
    // Read in input: n is the number of days, p is the number of political parties
    cin >> n >> p;
    for (int i = 0; i < p; i++)
      cin >> h[i];

    total = 0;

    for (int i = 1; i <= n; i++) { // For each day from 1 to n
      if (i % 7 == 6 || i % 7 == 0) continue; // If it's a Friday or Saturday, we skip
      // If it is divisible by any of the political parties' days, they go on strike
      for (int j = 0; j < p; j++) {
        if (i % h[j] == 0) {
          total++;
          break;
        }
      }
    }

    cout << total << endl;
  }

  return 0;
}
