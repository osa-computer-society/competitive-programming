// Problem ID: 706
// By Alexander Cai 12-06-2019

#include <iostream>
#include <string>
using namespace std;

const bool nums[10][7] = {
  { 1, 1, 1, 0, 1, 1, 1 },
  { 0, 0, 1, 0, 0, 1, 0 },
  { 1, 0, 1, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 0, 1, 1, 1, 0, 1, 0 },
  { 1, 1, 0, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 1, 1, 1 },
  { 1, 0, 1, 0, 0, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 }
};

void print_hori(string n, int s, int pos) {
  for (int i = 0; i < n.size(); i++) {
    if (i) cout << ' ';
    cout << ' ' << string(s, nums[n[i]-'0'][pos] ? '-' : ' ') << ' ';
  }
}

int main() {
  int s;
  string n;
  while (cin >> s >> n) {
    if (s == 0) break;

    print_hori(n, s, 0);
    cout << endl;

    for (int j = 0; j < s; j++) {
      for (int i = 0; i < n.size(); i++) {
        if (i) cout << ' ';
        cout << (nums[n[i]-'0'][1] ? '|' : ' ') << string(s, ' ') << (nums[n[i]-'0'][2] ? '|' : ' ');
      }
      cout << endl;
    }

    print_hori(n, s, 3);
    cout << endl;

    for (int j = 0; j < s; j++) {
      for (int i = 0; i < n.size(); i++) {
        if (i) cout << ' ';
        cout << (nums[n[i]-'0'][4] ? '|' : ' ') << string(s, ' ') << (nums[n[i]-'0'][5] ? '|' : ' ');
      }
      cout << endl;
    }

    print_hori(n, s, 6);
    cout << endl << endl;
  }

  return 0;
}
