// Problem ID: 10258
// By Alexander Cai 2019-06-20
// Accepted

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#define DEBUG // Comment this line to turn debugging on and off
#define MAXCONTESTANTS 101
#define NUMPROBLEMS 10
using namespace std;

struct Contestant {
  vector<int> attempts;
  int time_penalty, num;
  set<int> solved;

  Contestant(): solved(), attempts(NUMPROBLEMS, 0), time_penalty(0), num(0) {};
};

bool sort_contestants(Contestant const &lhs, Contestant const &rhs) {
  if (lhs.solved.size() != rhs.solved.size())
    return lhs.solved.size() > rhs.solved.size();
  if (lhs.time_penalty != rhs.time_penalty)
    return lhs.time_penalty < rhs.time_penalty;
  return lhs.num < rhs.num;
}

void log(string s) {
  cout << s << endl;
}

int main() {
  int ncases;
  cin >> ncases;
  cin.ignore();
  cin.ignore();

  string temp;
  // Main loop for each case
  while (ncases--) {
    vector<Contestant> contestants(MAXCONTESTANTS);
    
    while (getline(cin, temp) && temp != "") {
      stringstream ss(temp);
      int c, p, t; // c is the contestant number, p is the problem number, t is the time taken
      char l;
      ss >> c >> p >> t >> l;
      if (!contestants[c].num) contestants[c].num = c;

      if (contestants[c].solved.count(p) == 0) { // If they have not yet solved it
        if (l == 'I') {
          contestants[c].attempts[p]++;
        } else if (l == 'C') {
          contestants[c].solved.insert(p);
          contestants[c].time_penalty += contestants[c].attempts[p] * 20 + t;
        }
      }
    }

    sort(contestants.begin(), contestants.end(), &sort_contestants);

    for (int i = 0; i < MAXCONTESTANTS; i++)
      if (contestants[i].num)
        cout << contestants[i].num << ' ' << contestants[i].solved.size() << ' ' << contestants[i].time_penalty << endl;

    if (ncases) cout << endl;
  }
  return 0;
}
