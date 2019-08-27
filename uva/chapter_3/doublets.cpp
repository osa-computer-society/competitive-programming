// Problem ID: 10150
// By Alexander Cai 2019-08-27
// Accepted

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> dict[20]; // an array of vectors, each element is a length of input
unordered_map<string,vector<string> > adj_mat; // an adjacency matrix
bool computed_adj_mat[20] = {false};

bool doublet(string s1, string s2) {
  int matched = 0;
  for (int i = 0; i < s1.size(); i++)
    if (s1[i] != s2[i] && ++matched > 1)
      return false;
  return true;
}

void compute_adj_mat(vector<string> dict) {
  for (int i = 0; i < dict.size(); i++)
    for (int j = i + 1; j < dict.size(); j++)
      if (doublet(dict[i], dict[j])) {
        adj_mat[dict[i]].push_back(dict[j]);
        adj_mat[dict[j]].push_back(dict[i]);
      }
}

vector<string> bfs(string src, string dest) {
  unordered_map<string,string> parent;
  queue<string> q;
  q.push(src);
  parent[src] = "";
  bool found = false;

  while (!q.empty()) {
    string s = q.front(); q.pop();
    for (int i = 0; i < adj_mat[s].size(); i++) {
      string adj = adj_mat[s][i];
      if (!parent.count(adj)) { // If the adjacent word is not in the adjacency matrix
        q.push(adj);
        parent[adj] = s;
        if (adj == dest) {
          found = true;
          break;
        }
      }
    }
    if (found) break;
  }

  vector<string> result;
  if (!found) {
    result.push_back("No solution.");
  } else {
    string next = dest;
    do {
      result.push_back(next);
      next = parent[next];
    } while (result.back() != src);
  }

  return result;
}

int main() {
  string word;
  while (getline(cin, word) && !word.empty())
    dict[word.size()].push_back(word);

  int n = 0;
  string phrase, w1, w2;
  while (getline(cin, phrase) && !phrase.empty() && ++n) {
    if (n > 1) cout << endl;
    stringstream ss(phrase);
    ss >> w1 >> w2;
    if (w1.size() != w2.size())
      cout << "No solution." << endl;
    else {
      int len = w1.size();
      if (!computed_adj_mat[len]) {
        compute_adj_mat(dict[len]);
        computed_adj_mat[len] = true;
      }
      vector<string> path = bfs(w1, w2);
      for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << endl;
    }
  }
  return 0;
}
