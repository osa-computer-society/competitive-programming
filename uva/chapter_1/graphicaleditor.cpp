// Problem ID: 10267
// By Alexander Cai 13-06-2019
// Accepted

#include <iostream>
#include <string>
using namespace std;

// n is the number of rows
// m is the number of columns
int x, y, x1, y1, x2, y2, m, n;
char c;
string name;
char image[250][250];

void put(int x, int y, char c) {
  image[y-1][x-1] = c;
}

char get_char(int x, int y) {
  return image[y-1][x-1];
}

void fill(int tx, int ty, char prev, char k) {
  if (tx < 1 || ty < 1 || tx > m || ty > n) return;
  if (get_char(tx, ty) != prev) return;
  put(tx, ty, k);
  fill(tx-1, ty, prev, k);
  fill(tx+1, ty, prev, k);
  fill(tx, ty-1, prev, k);
  fill(tx, ty+1, prev, k);
}

int main() {
  char cmd;
  while (cin >> cmd && cmd != 'X') {
    switch (cmd) {
      case 'I':
        cin >> m >> n;
        for (int r = 0; r < n; r++) 
          for (int c = 0; c < m; c++)
            image[r][c] = 'O';
        break;

      case 'C':
        for (int r = 0; r < n; r++) 
          for (int c = 0; c < m; c++)
            image[r][c] = 'O';
        break;

      case 'L':
        cin >> x >> y >> c;
        put(x, y, c);
        break;

      case 'V':
        cin >> x >> y1 >> y2 >> c;
        if (y1 > y2) swap(y1, y2);
        for (int i = y1; i <= y2; i++)
          put(x, i, c);
        break;

      case 'H':
        cin >> x1 >> x2 >> y >> c;
        if (x1 > x2) swap(x1, x2);
        for (int i = x1; i <= x2; i++)
          put(i, y, c);
        break;

      case 'K':
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int i = x1; i <= x2; i++)
          for (int j = y1; j <= y2; j++)
            put(i, j, c);
        break;

      case 'F':
        cin >> x >> y >> c;
        if (get_char(x, y) != c) fill(x, y, get_char(x, y), c);
        break;

      case 'S':
        cin >> name;
        cout << name << endl;
        for (int r = 0; r < n; r++) {
          for (int c = 0; c < m; c++)
            cout << image[r][c];
          cout << endl;
        }
        break;

      default:
        string temp;
        getline(cin, temp);
    }
  }
  return 0;
}
