// solved
// alexander cai 18 jan 2021

#include <iostream>
using namespace std;

bool valid(int n)
{
  // cout << n << '\n';
  int flip = 0;
  int dig;

  int t = n;
  while (n != 0)
  {
    flip *= 10;
    dig = n % 10;
    n /= 10;

    if (dig == 2 || dig == 3 || dig == 4 || dig == 5 || dig == 7)
      return false;
    if (dig == 6)
      flip += 9;
    else if (dig == 9)
      flip += 6;
    else
      flip += dig;
  }

  // cout << n << ", " << flip << "\n";

  return flip == t;
}

int main()
{
  int m, n;
  cin >> m >> n;

  int total = 0;
  for (int i = m; i <= n; ++i)
  {
    if (valid(i))
      total++;
  }

  cout << total << '\n';
  return 0;
}