// Problem ID: 10044
// By Alexander Cai 2019-06-19
// Accepted
// P.S. Don't trust the UVa Online Judge test on uDebug, it's broken -- It said my code was incorrect but the judge still accepted it

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
// #define DEBUG
using namespace std;

const string delim = "., ";

void bfs(map<string,int> &erdos_ns, map<string,vector<string> > coauthors) {
  queue<string> Q;
  Q.push("Erdos, P.");

  while(!Q.empty()) {
    string co1 = Q.front(); Q.pop();
    for (string co : coauthors[co1]) { // For each of their coauthors
      if (erdos_ns[co] == -1 || erdos_ns[co] > erdos_ns[co1] + 1) {
        erdos_ns[co] = erdos_ns[co1] + 1; // We give them an erdos number 1 greater than the current one
        Q.push(co);
      }
    }
  }
}

int main() {
  int nscenarios;
  cin >> nscenarios;
  for (int scen = 1; scen <= nscenarios; scen++) {
    map<string,int> erdos_ns;
    map<string,vector<string> > coauthors;

    int p, n;
    cin >> p >> n;
    cin.ignore();

    while (p--) { // We read in p papers
      string paper;
      vector<string> authors;
      getline(cin, paper);
      paper = paper.substr(0, paper.find(':'));

      size_t pos = 0;
      while ((pos = paper.find(delim)) != string::npos) {
        authors.push_back(paper.substr(0, pos + 1));
        paper.erase(0, pos + delim.size());
      }

      if (paper != "")
        authors.push_back(paper);
      
      for (string s : authors)
        erdos_ns[s] = -1;

      for (auto a : authors)
        for (auto b : authors)
          if (a != b)
            coauthors[a].push_back(b);
    } // Finish reading papers

    erdos_ns["Erdos, P."] = 0;
    vector<string> names_to_find;
    string temp;
    for (int i = 0; i < n; i++) {
      getline(cin, temp);
      names_to_find.push_back(temp);
    }

    bfs(erdos_ns, coauthors);
    cout << "Scenario " << scen << endl;
    for (string name : names_to_find) {
      cout << name << ' ';
      if (erdos_ns[name] == -1 || (coauthors.find(name) == coauthors.end())) cout << "infinity";
      else cout << erdos_ns[name];
      cout << endl;
    }
  }
  return 0;
}
