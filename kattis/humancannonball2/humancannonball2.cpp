#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double v, theta, x, h1, h2, t, y;
  for (int i = 0; i < n; i++) {
    cin >> v >> theta >> x >> h1 >> h2;
    theta = theta * M_PI / 180;
    t = x / (v * cos(theta));
    y = v * t * sin(theta) - (9.81 * pow(t, 2) * 0.5);
    if (h1 + 1 < y && y < h2 - 1) {
      cout << "Safe" << endl;
    } else {
      cout << "Not Safe" << endl;
    }
  }

  return 0;
}
