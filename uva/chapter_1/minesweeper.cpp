// Problem ID: 10189
// By Alexander Cai, 12-06-2019
// Accepted

#include <iostream>
#include <vector>
using namespace std;

// Arrays to store the relative coordinates of the surrounding squares
const int drow[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dcol[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main() {
  int n, m, field = 0;
  char t;

  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;

    // Stores the input
    vector<vector<char> > grid(n, vector<char>());
    // Stores the number of mines by each square
    vector<vector<int> > count(n, vector<int>(m, 0));

    // Get input
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> t;
        grid[i].push_back(t);
      }
    }

    // For each square, if it is a mine, we add to all the squares around it
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (grid[r][c] == '*') {
          for (int i = 0; i < 8; i++) {
            int nr = r + drow[i], nc = c + dcol[i];
            // Check for out of bounds
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            count[nr][nc]++;
          }
        }
      }
    }

    // Display the grid
    if (field) cout << endl;
    cout << "Field #" << field + 1 << ":" << endl;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        // If the square is a star we output a star
        if (grid[r][c] == '*') cout << '*';
        // Otherwise we output the number of mines next to the square
        else cout << count[r][c];
      }
      cout << endl;
    }

    field++;
  }

  return 0;
}
