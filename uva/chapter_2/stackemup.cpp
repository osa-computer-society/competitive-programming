// Problem ID: 10205
// By Alexander Cai 2019-06-18
// Accepted

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define NVALUES 13
using namespace std;

const string values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
const string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

int main() {
  int ncases;
  cin >> ncases;

  // Loop for each case
  while (ncases--) {
    int n;
    cin >> n;
    vector<int> shuffles[n];

    for (int j = 0; j < n; j++) {
      shuffles[j] = vector<int>(52);
      for (int k = 0; k < 52; k++) {
        cin >> shuffles[j][k];
        shuffles[j][k]--;
      }
    }
    cin.ignore();

    string line;
    vector<int> shuffle_order;
    while (getline(cin, line) && line != "")
      shuffle_order.push_back(atoi(line.c_str()) - 1);

    for (int i = 0; i < 52; i++) {
      int pos = i;
      for (int j = shuffle_order.size() - 1; j >= 0; j--)
        pos = shuffles[shuffle_order[j]][pos];
      cout << values[pos % NVALUES] << " of " << suits[pos / NVALUES] << endl;
    }

    if (ncases) cout << endl;
  }

  return 0;
}
