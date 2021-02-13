# USACO 2019 December Contest, Bronze

## 2. Where Am I

*(Analysis by Nick Wu)*

Because N is at most 100, one approach that comes to mind is checking if K=1 is valid. If so, then the answer is 1 and we can stop. Otherwise, we check if K=2 is valid. We'll keep on increasing K until it reaches N, as K=N is guaranteed to be valid.

How do we check if a given value of K is valid? We can loop over all pairs of substrings of length K and compare them for equality. My code following this approach is as follows:

```cpp
#include <iostream>

using namespace std;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  int n;
  string s;
  cin >> n >> s;
  for(int guess = 1; guess <= n; guess++) {
    bool good = true;
    for(int i = 0; i + guess <= n; i++) {
      for(int j = 0; j < i; j++) {
        if(s.substr(i, guess) == s.substr(j, guess)) {
          good = false;
        }
      }
    }
    if(good) {
      cout << guess << "\n";
      break;
    }
  }
}
```

It is possible to do faster by using a data structure known as a set. Sets cannot store duplicate elements but are able to quickly identify if a given element is already part of the set. Therefore, to check if a given value of K is valid using a set, we can check if a substring is present in the set before inserting it. If some substring is already present, then the given value of K is invalid.

Here is Brian Dean's solution using a set.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int N;
string S;

bool dups(int len)
{
  set<string> X;
  for (int i=0; i<=N-len; i++) {
    if (X.count(S.substr(i,len)) > 0) return true;
    X.insert(S.substr(i,len));
  }
  return false;
}

int main(void)
{
  ifstream fin ("whereami.in");
  ofstream fout ("whereami.out");
  fin >> N >> S;
  int ans = 1;
  while (dups(ans)) ans++;
  fout << ans << "\n";
  return 0;
}
```
