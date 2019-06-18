// Question 3 of the CCC 2018 Senior
// By Alexander Cai 17-06-2019

#include <iostream>
#include <queue>
#define MAXROWS 101
#define MAXCOLS 101
#define MARKED 0
using namespace std;

int n, m;
char grid[MAXROWS][MAXCOLS];
int distances[MAXROWS][MAXCOLS];

int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, 1, -1, 0 };

struct node {
  int r, c;
  node(int r = 0, int c = 0) : r(r), c(c) {}
};

void mark_camera(int r, int c) {
  for (int i = 0; i < 4; i++) // For each of the 4 directions
    for (int r1 = r + dr[i], c1 = c + dc[i]; ; r1 += dr[i], c1 += dc[i])
      if (grid[r1][c1] == '.' || grid[r1][c1] == 'S')
        distances[r1][c1] = MARKED;
      else if (grid[r1][c1] == 'W') break;
}

// Returns true if the conveyor belt ends in an empty cell
bool conveyor(node &x) {
  node y = x;
  while (true) {
    switch (grid[y.r][y.c]) {
    case 'U': y.r--; break;
    case 'D': y.r++; break;
    case 'L': y.c--; break;
    case 'R': y.c++; break;
    default: return false; break;
    }

    if (grid[y.r][y.c] == '.') {
      if (distances[y.r][y.c] >= 0)
        return false;
      else {
        x = y;
        return true;
      }
    } else if (distances[y.r][y.c] < 0) {
      distances[y.r][y.c] = 0;
      continue;
    } else return false;
  }
}

void bfs(int ri, int ci) {
  queue<node> to_search;
  node x(ri, ci);
  distances[ri][ci] = 0;
  to_search.push(x);

  while (!to_search.empty()) {
    x = to_search.front();
    to_search.pop();

    for (int i = 0; i < 4; i++) { // Each direction
      node y(x.r + dr[i], x.c + dc[i]);
      char val = grid[y.r][y.c];
      if (val == 'W' || val == 'C') continue;
      else {
        if (val == '.') {
          if (distances[y.r][y.c] < 0) {
            distances[y.r][y.c] = distances[x.r][x.c] + 1;
            to_search.push(y);
          }
        } else if (conveyor(y)) {
          distances[y.r][y.c] = distances[x.r][x.c] + 1;
          to_search.push(y);
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  int ri, ci;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> grid[r][c];
      distances[r][c] = -1;
      if (grid[r][c] == 'S') { ri = r; ci = c; }
      if (grid[r][c] == 'W' || grid[r][c] == 'C') distances[r][c] = MARKED;
    }
  }

  for (int r = 1; r < n-1; r++)
    for (int c = 1; c < m-1; c++)
      if (grid[r][c] == 'C')
        mark_camera(r, c);

  if (distances[ri][ci] == MARKED) {
    for (int r = 0; r < n; r++)
      for (int c = 0; c < m; c++)
        if (grid[r][c] == '.')
          cout << -1 << endl;
    return 0;
  }

  bfs(ri, ci);

  for (int r = 1; r < n-1; r++)
    for (int c = 1; c < m-1; c++)
      if (grid[r][c] == '.')
        cout << (distances[r][c] ? distances[r][c] : -1) << endl;

  return 0;
}
