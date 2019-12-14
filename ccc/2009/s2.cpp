// Problem ID: CCC '09 S2
// By Alexander Cai
// SEE PYTHON SOLUTION -- THIS ONE DOES NOT WORK

#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  unordered_set<ll> results;
  ll r, l, t;
  cin >> r >> l;
  if (r == 1)
  {
    cout << 1;
    return 0;
  }

  vector<ll> lines;
  for (ll i = 0; i < r; i++)
  {
    stringstream ss;
    for (ll j = 0; j < l; j++)
    {
      cin >> t;
      ss << t;
    }
    lines.push_back(stoi(ss.str(), 0, 2));
  }

  set<ll> lows, highs = {lines[0]};
  for (ll i = 1; i < r; i++)
  {
    lows = {lines[i]};
    for (ll i : highs)
      lows.insert(i ^ lines[i]);
    highs = lows;
  }
  
  cout << lows.size();

  return 0;
}
