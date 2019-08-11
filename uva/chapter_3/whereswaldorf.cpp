// Problem ID: 10010
// By Alexander Cai 2019-08-10
// Accepted

#include <iostream>
#define MAX_SIZE 55
#define MAX_SEARCH_TERMS 25
#define to_lower(c) ((c >= 'A' && c <= 'Z') ? (c-'A'+'a') : (c))

using namespace std;

char map[MAX_SIZE][MAX_SIZE];

int directions[][2]{
  {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
};

void find(int m, int n, string word) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int d = 0; d < 8; d++) { // For each direction
        int r(i), c(j), idx(0);
        while (map[r][c] == word[idx] && r >= 0 && r < m && c >= 0 && c < n) {
          r += directions[d][0];
          c += directions[d][1];
          idx++;
          if (word[idx] == '\0') {
            cout << i + 1 << ' ' << j + 1 << endl;
            return;
          }
        }
      }
    }
  }
}

int main() {
  int n_cases, m, n, k;
  string search;
  cin >> n_cases;

  while (n_cases--) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> map[i][j];
        map[i][j] = to_lower(map[i][j]);
      }
    }
    cin >> k;
    cin.ignore();
    while (k--) {
      getline(cin, search);
      for (int i = 0; search[i]; i++) {
        search[i] = to_lower(search[i]);
      }
      find(m, n, search);
    }
    if (n_cases) cout << endl;
  }

  return 0;
}

