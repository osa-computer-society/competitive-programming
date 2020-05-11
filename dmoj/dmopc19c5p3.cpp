#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}


int main() {
  int H, V;
  cin >> H >> V;

  ll ans = 0;

  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= V; x++) {
      ll g = gcd(x, y), dx = x/g, dy = y/g;
      for (int r = y + dx, c = x + dy; r <= H && c <= V; r += dx, c += dy)
        ans += (H-r)*(V-c);
    }
  }

  cout << ans + (H*(H-1)*V*(V-1))/4 << '\n';
}