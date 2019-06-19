// Problem ID: 843
// By Alexander Cai 19-06-2019
// Accepted

#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#define ENCODED '*'
using namespace std;

string word_shape(string word) {
  stringstream ss;
  map<char,int> met;
  int i = 1;
  for (char c : word) {
    if (met.find(c) == met.end()) {
      met.insert(pair<char,int>(c, i));
      ss << i; i++;
    } else ss << met[c];
  }
  return ss.str();
}

#ifdef DEBUG
void debug_words(const map<string,set<string> > &words) {
  for (auto kv : words) {
    cout << kv.first << ": [ ";
    for (auto w : kv.second)
      cout << w << ", ";
    cout << "]" << endl;
  }
}

void debug_decrypt(const vector<char> &decrypt) {
  cout << "[ ";
  for (int i = 0; i < decrypt.size(); i++) {
    char n = 'a' + i;
    if (decrypt[i]) cout << n << decrypt[i] << ", ";
    else cout << n << "_, ";
  }
  cout << "]" << endl;
}
#endif

bool run_decrypt(const vector<string> words, int ind, map<string,set<string> > &valid_words, vector<char> &decrypt) {
  if (ind >= words.size()) return true;

  string word = words[ind];
  int len = word.size();
  string shape = word_shape(word);

  if (valid_words.count(shape) <= 0) return false;

  #ifdef DEBUG
  debug_decrypt(decrypt);
  #endif

  string decoded(len, ENCODED);
  for (int i = 0; i < len; i++)
    if (decrypt[word[i] - 'a'] != 0)
      decoded[i] = decrypt[word[i] - 'a'];

  for (auto poss : valid_words[shape]) {
    bool match = true;
    for (int i = 0; i < len; i++)
      if ((decoded[i] != ENCODED && poss[i] != decoded[i]))
        match = false;
    if (!match) continue;

    match = true;
    for (int i = 0; i < len; i++) {
      if (decoded[i] == ENCODED) {
        for (char c : decrypt)
          if (c == poss[i])
            match = false;
      }
    }
    if (!match) continue;

    for (int i = 0; i < len; i++)
      if (decoded[i] == ENCODED)
        decrypt[word[i] - 'a'] = poss[i];

    if (run_decrypt(words, ind + 1, valid_words, decrypt))
      return true;
    else
      for (int i = 0; i < len; i++)
        if (decoded[i] == ENCODED)
          decrypt[word[i] - 'a'] = 0;
  }

  return false;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  map<string,set<string> > words;

  string word, shape;
  while (n--) {
    getline(cin, word);
    shape = word_shape(word);
    if (words.count(shape) == 0)
      words[shape] = set<string>();
    words[shape].insert(word);
  }

  #ifdef DEBUG
  debug_words(words);
  #endif

  // Main loop for each entered sentence
  string sentence;
  while (getline(cin, sentence)) {
    stringstream ss(sentence);
    vector<string> line;

    while (ss >> word)
      line.push_back(word);

    #ifdef DEBUG
    cout << "line: [ ";
    for (auto w : line) cout << w << ", ";
    cout << "]" << endl;
    #endif

    vector<char> decrypt(26, 0);
    bool decrypted = run_decrypt(line, 0, words, decrypt);
    for (int i = 0; i < line.size(); i++) {
      for (auto &c : line[i]) 
        cout << (decrypted ? decrypt[c-'a'] : '*');
      if (i == line.size() - 1)
        cout << endl;
      else
        cout << ' ';
    }

  }

  return 0;
}
