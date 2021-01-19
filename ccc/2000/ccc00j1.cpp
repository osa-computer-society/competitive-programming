// This solution is probably overly complex, but it does the job.
// Alexander Cai 18 Jan 2021

#include <iostream>
#include <string>
using namespace std;

string names[] = {
    "Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};

int main()
{
  int startday, ndays;
  cin >> startday >> ndays;

  for (int i = 0; i < 6; ++i)
    cout << names[i] << ' ';
  cout << names[6] << '\n';

  for (int i = 0; i < startday - 1; ++i)
  {
    cout << "    ";
  }

  // print first row
  int date = 1;
  while (true)
  {
    int dayofweek = (startday + date - 1) % 7;

    if (date < 10)
      cout << ' ';
    cout << ' ' << date;

    if (date == ndays)
      break;

    if (dayofweek == 0)
    {
      cout << '\n';
    }
    else
      cout << ' ';
    
    date++;
  }
  cout << '\n';

  return 0;
}