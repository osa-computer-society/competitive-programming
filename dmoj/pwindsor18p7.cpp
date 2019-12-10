// Problem ID: pwindsor18p7
// By Alexander Cai 9 Dec 2019
// Solved

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {
  return a + b > b + a;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string t;
  cin >> n;
  vector<string> v;
  while (n--) {
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end(), cmp);
  for (string s : v) cout << s;
  return 0;
}
