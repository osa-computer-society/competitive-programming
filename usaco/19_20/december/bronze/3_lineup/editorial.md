# USACO 2019 December Contest, Bronze

## 3. Livestock Lineup

*(Analysis by Nick Wu)*

There are two approaches to this problem, a brute force one that tries all ordering and a more analytical one that tries to build up the alphabetically first ordering one cow at a time.

Because there are only 8 cows, there are 8×7×6×5×4×3×2×1=40320 different orderings, which is small enough that we can try all of them. If we generate them in alphabetic ordering and stop when we see one that satisfies all the given constraints, then we can print the answer then and there. Here is Brian Dean's code following this approach:

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cows, beside_a, beside_b;
int N;

int where(string c)
{
  for (int i=0; i<8; i++)
    if (cows[i]==c) return i;
  return -1;
}

bool satisfies_constraints(void)
{
  for (int i=0; i<N; i++)
    if (abs(where(beside_a[i]) - where(beside_b[i])) != 1) return false;
  return true;
}

int main(void)
{
  ifstream fin ("lineup.in");
  ofstream fout ("lineup.out");
  fin >> N;
  cows.push_back("Beatrice");
  cows.push_back("Belinda");
  cows.push_back("Bella");
  cows.push_back("Bessie");
  cows.push_back("Betsy");
  cows.push_back("Blue");
  cows.push_back("Buttercup");
  cows.push_back("Sue");
  string a, b, t;
  for (int i=0; i<N; i++) {
    fin >> a;
    fin >> t; // must
    fin >> t; // be
    fin >> t; // milked
    fin >> t; // beside
    fin >> b;
    beside_a.push_back(a);
    beside_b.push_back(b);
  }
  do {
    if (satisfies_constraints()) {
      for (int i=0; i<8; i++) fout << cows[i] << "\n";
      break;
    }
  } while (next_permutation(cows.begin(), cows.end()));
  return 0;
}
The more analytic approach tries to build the ordering one cow at a time. We start by asking the question - can Beatrice be the very first cow in the ordering? It turns out that the answer is yes, if and only if Beatrice must be next to at most one cow. If Beatrice has to be next to two cows, then one of the cows must be in front of her. On the other hand, if Beatrice needs to be next to only one cow, then we can put Beatrice first in line, and then the cow who needs to be beside her goes immediately after. Similarly, if Beatrice doesn't need to be next to any cows, we can move her to the front of the line.

We can loop over the cows in alphabetic order to find the cow that should go first in line. What about the cows that come after? If the cow currently at the end of the ordering must be next to some other cow, then that cow is forced to be next in line. Otherwise, we are free to pick any cow we wish, and we apply the procedure in the previous paragraph to figure out the next cow to put in line.

Here is Brian Dean's code simulating this approach:

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cows, beside_a, beside_b, answer;
int N;

int where(string c)
{
  for (int i=0; i<answer.size(); i++)
    if (answer[i]==c) return i;
  return 999;
}

bool can_go_first(string c)
{
  int n = answer.size(), nbrs=0;
  if (where(c)!=999) return false;
  for (int i=0; i<N; i++) {
    if (beside_a[i]==c && where(beside_b[i])==999) nbrs++;
    if (beside_b[i]==c && where(beside_a[i])==999) nbrs++;
  }
  if (nbrs == 2) return false;
  if (n>0) {
    string last_cow = answer[n-1];
    for (int i=0; i<N; i++) {
      if (beside_a[i]==last_cow && where(beside_b[i])==999 && beside_b[i]!=c) return false;
      if (beside_b[i]==last_cow && where(beside_a[i])==999 && beside_a[i]!=c) return false;
    }
  }
  return true;
}

int main(void)
{
  ifstream fin ("lineup.in");
  ofstream fout ("lineup.out");
  fin >> N;
  cows.push_back("Beatrice");
  cows.push_back("Belinda");
  cows.push_back("Bella");
  cows.push_back("Bessie");
  cows.push_back("Betsy");
  cows.push_back("Blue");
  cows.push_back("Buttercup");
  cows.push_back("Sue");
  string a, b, t;
  for (int i=0; i<N; i++) {
    fin >> a;
    fin >> t; // must
    fin >> t; // be
    fin >> t; // milked
    fin >> t; // beside
    fin >> b;
    beside_a.push_back(a);
    beside_b.push_back(b);
  }
  for (int i=0; i<8; i++) {
    int next_cow = 0;
    while (!can_go_first(cows[next_cow])) next_cow++;
    answer.push_back(cows[next_cow]);
    fout << cows[next_cow] << "\n";
  }
  return 0;
}
```
