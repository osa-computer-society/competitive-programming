// Problem ID on UVa: 100
// By Alexander Cai, 12-06-2019
// Accepted

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int cycle_length(int n) {
  int temp = n, length = 1;
  while (temp != 1) {
    if (temp % 2 == 0) temp >>= 1;
    else temp = temp * 3 + 1;
    length += 1;
  }
  return length;
}

int main() {
  int i, j, l, max;
  while (cin >> i >> j) {
    int ti = i, tj = j;
    if (i > j) swap(i, j);
    max = 1;
    for (int k = i; k <= j; k++) {
      l = cycle_length(k);
      if (l > max) max = l;
    }
    cout << ti << " " << tj << " " << max << endl;
  }

  return 0;
}
