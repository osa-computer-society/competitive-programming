#include <iostream>
using namespace std;

int main() {
  int s, n, m, t, prev, peaks = 0, valleys = 0, rise_len = 1, fall_len = 1;
  bool rising = false, falling = false;
  
  cin >> s >> n >> m;
  cin >> prev;

  for (int i = 1; i < s; i++) {
    cin >> t;
    if (t > prev) {
      if (rising) rise_len++;
      else {
        if (rise_len >= n && fall_len >= n) {
          peaks++;
        }
        rising = true; falling = false;
        rise_len = 2;
      }
    } else {
      if (falling) fall_len++;
      else {
        if (rise_len >= m && fall_len >= m) {
          valleys++;
        }
        rising = false; falling = true;
        fall_len = 2;
      }
    }
    prev = t;
  }

  if (falling && rise_len >= n && fall_len >= n) peaks++;
  if (rising && rise_len >= m && fall_len >= m) valleys++;

  cout << peaks << " " << valleys << endl;

  return 0;
}
