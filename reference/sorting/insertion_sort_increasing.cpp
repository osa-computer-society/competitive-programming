/*
 * This is a solution to exercise 2.1-2 on page 22 of CLRS.
 * by Alexander Cai, 9 June 2019
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
  int n, temp;
  cin >> n;
  for (int i = 0; i != n; ++i) {
    cin >> temp;
    vec.push_back(temp);
  }

  for (int i = 1; i != vec.size(); ++i) {
    int k = vec[i];
    int j = i - 1;

    while (j >= 0 && vec[j] < k) {
      vec[j+1] = vec[j];
      --j;
    }

    vec[j+1] = k;
  }

  for (auto i : vec)
    cout << i << endl;

  return 0;
}
