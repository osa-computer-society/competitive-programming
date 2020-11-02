// This is a generic C++ template for various problems.
// If the problem is from UVa, Kattis, etc., include the following line:
// Problem ID: [INSERT PROBLEM ID]
// (If from a contest, label it here)
// By [INSERT NAME HERE] [DD-MM-YYYY]

#include <iostream>
#include <map>
#include <string>
#include <vector>
#define DEBUG // Comment this line to turn debugging on and off
using namespace std;

// Allows the printing of pairs for maps
template <typename K, typename V>
ostream &operator<<(ostream &os, const pair<K, V> &p)
{
  os << p.first << " => " << p.second;
  return os;
}

// Print out a vector, map, set, or any other collection
template <typename Collection>
void log(string s, const Collection &c)
{
#ifdef DEBUG
  cout << s << ": [\n";
  for (typename Collection::const_iterator it = c.begin(); it != c.end(); it++)
    cout << "  " << *it << ",\n";
  cout << ']' << endl;
#endif
}

int main()
{
  vector<int> arr{3, 1, 4, 1, 5, 9};
  map<int, int> m; // {{1, 2}, {3, 4}};
  m[1] = 2;
  m[3] = 4;
  log("array", arr);
  log("map", m);
  return 0;
}
