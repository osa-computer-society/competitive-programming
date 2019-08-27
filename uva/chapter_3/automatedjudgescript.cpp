// Problem ID: 10188
// By Alexander Cai 2019-08-26
// Accepted

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n, m, run = 0;
string sol[105], ans[105];

bool accepted() {
  for (int i = 0; i < n; i++)
    if (sol[i] != ans[i])
      return false;
  return true;
}

int main() {
  while (cin >> n && n != 0) {
    cin.ignore();
    run++;
    cout << "Run #" << run << ": ";

    stringstream sol_nums, ans_nums;

    for (int i = 0; i < n; i++) {
      getline(cin, sol[i]);
      for (int j = 0; j < sol[i].length(); j++) {
        if (isdigit(sol[i][j]))
          sol_nums << sol[i][j];
      }
    }

    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
      getline(cin, ans[i]);
      for (int j = 0; j < ans[i].length(); j++) {
        if (isdigit(ans[i][j]))
          ans_nums << ans[i][j];
      }
    }

    if (n == m && accepted())
      cout << "Accepted";
    else if (sol_nums.str() == ans_nums.str())
      cout << "Presentation Error";
    else
      cout << "Wrong Answer";

    cout << endl;
  }
  return 0;
}
