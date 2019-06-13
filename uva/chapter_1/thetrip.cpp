// Problem ID: 10137
// By Alexander Cai, 12-06-2019
// Accepted

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) break;

    double total = 0, above = 0, below = 0, diff;
    vector<double> costs;

    double t;
    for (int i = 0; i < n; i++) {
      cin >> t;
      costs.push_back(t);
      total += t;
    }

    double avg = total / n, tempdiff;

    for (double c : costs) {
      // Since typecasting is higher in the order of operations, 
      // we first take the difference, multiply by 100 to bring the decimal place 
      // two digits forward, convert it to a long integer to trim the digits past 
      // the decimal, and put the decimal place back.
      // This brings the difference to within 0.01 of the average.
      diff = (long) ((c - avg) * 100.0) / 100.0; 

      if (c > avg) above += diff;
      else if (c < avg) below -= diff;
    }

    double change = max(above, below);

    // We use iomanip functions to print the cost properly
    cout << '$' << setprecision(2) << fixed << change << endl;
  }

  return 0;
}
