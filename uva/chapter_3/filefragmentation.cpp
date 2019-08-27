// Problem ID: 10132
// By Alexander Cai 2019-08-26
// Accepted

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  int n;
  ss >> n;
  getline(cin, s);

  while (n--) {
    string line;
    vector<string> lines;
    while (getline(cin, line) && !line.empty()) {
      lines.push_back(line);
    }

    map<string,int> memo;
    for (int i = 0; i < lines.size(); i++) {
      for (int j = i + 1; j < lines.size(); j++) {
        memo[lines[i] + lines[j]]++;
        memo[lines[j] + lines[i]]++;
      }
    }

    map<string,int>::iterator output(memo.begin());
    for (map<string,int>::iterator it(memo.begin()); it != memo.end(); it++)
      if (it->second > output->second)
        output = it;
    cout << output->first << endl;
    if (n) cout << endl;
  }
  return 0;
}
