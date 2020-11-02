#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<char> all; // A vector to contain all of the characters (at most 10)
vector<int> permutation;
vector<bool> chosen(10, false);

unordered_set<char> first_letters;
unordered_set<char> seen;

unordered_map<char, int> addend_map;
unordered_map<char, int> total_map;

int total_solutions = 0, pos = 0;

void search() {
  // If we have a digit selected for each character
  if (permutation.size() == all.size()) {
    int addend_sum = 0, total_value = 0;
    // all[i] contains the character
    // addend/total_map[all[i]] contains the sum of the the place values of the character
    // permutation[i] contains the digit that character is associated with
    for (int i = 0; i < all.size(); i++) {
      addend_sum += addend_map[all[i]] * permutation[i];
      total_value += total_map[all[i]] * permutation[i];
    }

    if (addend_sum == total_value) total_solutions++;
  } else {
    // For each digit, we recursively loop through until we have a full permutation,
    // i.e. a digit associated with each character
    // first_letters.count(all[pos]) > 0 means that it is the first letter of the word,
    // So it cannot be 0 and we can skip a few cases.
    // pos is the index of the character we are currently picking a digit for.
    for (int i = 0; i < 10; i++) {
      if (chosen[i] || (i == 0 && (first_letters.count(all[pos]) > 0))) continue;
      pos++;
      chosen[i] = true;
      permutation.push_back(i);
      search(); // Recursively fill a whole permutation of digits
      permutation.pop_back();
      chosen[i] = false;
      pos--;
    }
  }
}

int main() {
  int n;
  cin >> n;

  string s;

  // Get the addends
  for (int i = 0; i < n - 1; i++) {
    cin >> s;
    first_letters.insert(s.front());
    reverse(s.begin(), s.end());

    // Add the place value from the character's current position to
    // its total place values,
    // And insert all of the letters into the seen set
    for (int j = 0; j < s.size(); j++) {
      addend_map[s[j]] += pow(10, j);
      seen.insert(s[j]);
    }
  }

  // Get the sum
  cin >> s;
  first_letters.insert(s.front());
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) {
    total_map[s[i]] += pow(10, i);
    seen.insert(s[i]);
  }
  
  for (auto i : seen) all.push_back(i);

  search();

  cout << total_solutions << endl;

  return 0;
}
