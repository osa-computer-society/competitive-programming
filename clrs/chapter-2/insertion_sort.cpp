/*
 * This is an implementation of insertion sort in C++, based
 * off the pseudocode on page 18 of CLRS.
 * by Alexander Cai, 9 June 2019
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
  int n, temp;
  // Get the number of numbers to retrieve
  cin >> n;

  // Feed n numbers into the vector
  for (int i = 0; i != n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }

  // For each index `i` in the array:
  for (int i = 1; i != arr.size(); ++i) {
    // First we store the value at that index in that array in `key`
    int key = arr[i];
    // We initialize `j` to the index before `i`
    int j = i - 1;

    // We go backwards, checking the previous value to see if it is greater than the current value.
    // If we reach the end of the array or the value is larger, we stop and put the value of `key` at that index
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      --j;
    }

    arr[j+1] = key;
  }

  // Prints the sorted vector
  for (auto i : arr) {
    cout << i << endl;
  }

  return 0;
}
