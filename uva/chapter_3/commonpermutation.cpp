// Problem ID: 10252
// By Alexander Cai 2019-08-11
// Accepted

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<char,int> common;

int main() {
  string a, b;
  vector<char> both;

  while (getline(cin, a) && getline(cin, b)) {
    both.clear();
    common.clear();

    for (int i = 0; i < a.length(); i++) {
      auto idx = b.find(a[i], common[a[i]]);
      if (idx != string::npos) {
        both.push_back(a[i]);
        if (!common.count(a[i]))
          common.insert(pair<char,int>(a[i], idx + 1));
        else
          common[a[i]] = idx + 1;
      }
    }

    sort(both.begin(), both.end());
    for (auto it = both.begin(); it != both.end(); it++)
      cout << *it;
    cout << endl;
  }
  return 0;
}
