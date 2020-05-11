// Problem ID: coci06c3p2.cpp
// By 

#include <iostream>
using namespace std;

char grid[5][5];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int tot = 0;
  char l;
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      cin >> l;
      if (l == '.') continue;
      int rr = (l-'A') / 4, cc = (l-'A') % 4;
      tot += abs(rr-r) + abs(cc-c);
    }
  }

  cout << tot << '\n';

  return 0;
}
