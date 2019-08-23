// Problem ID: 850
// By Alexander Cai 2019-08-22
// Accepted
// With help from https://codingstrife.wordpress.com/2013/07/11/solution-uva843-pc110204-crypt-kicker/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
 
char mappings[128];
vector<string> alphabet_words;
bool mapLetters(vector<string> encrypted) { 
    for (int i = 0; i < 128; i++)
        mappings[i] = 0;
 
    for (int i = 0; i < alphabet_words.size(); i++) {
        for (int j = 0; j < alphabet_words[i].length(); j++) {
            if (!mappings[encrypted[i][j]]
                || (mappings[encrypted[i][j]] == alphabet_words[i][j]))
                mappings[encrypted[i][j]] = alphabet_words[i][j];
            else return false;
        }
    }
 
    return true;
}

int main() {
    int N;
 
    cin >> N;
    cin.get();
    string alphabet = "the quick brown fox jumps over the lazy dog";
    stringstream s(alphabet);
 
    while(!s.eof()) {
        string T;
        s >> T;
        alphabet_words.push_back(T);
    }
 
    for (int i = 0; i < N; i++) {
        cin.get(); // ignore line break
        // a 2d vector, each element represents a line of input as a vector of words
        vector<vector<string> > input_words;
        while (true) {
            if (cin.peek() == '\n' || cin.eof()) break;
            input_words.push_back(*(new vector<string>));
            string line;
            getline(cin, line);
            stringstream s(line);
 
            while (!s.eof()) {
                s >> line; // use line as a placeholder
                input_words[input_words.size()-1].push_back(line);
            }
        }
 
        bool possible = false;
        // For each line of input
        for (int i = 0; i < input_words.size(); i++) {
            // If it has the same number of words
            if (input_words[i].size() == alphabet_words.size()) {
                possible = true;
                for (int j = 0; j < input_words[i].size(); j++)
                    if (input_words[i][j].length() != alphabet_words[j].length())
                        possible = false;

                if (possible) {
                    if (!mapLetters(input_words[i])) possible = false;
                    else break;
                }
            }
        }
     
        if (possible) {
            // We loop through each character of each word of each line and decrypt it
            for (int j = 0; j < input_words.size(); j++) {
                for (int k = 0; k < input_words[j].size(); k++) {
                    for (int l = 0; l < input_words[j][k].length(); l++)
                        cout << mappings[input_words[j][k][l]];
                    if (k != input_words[j].size() - 1) cout << " ";
                }
                if (j != input_words.size()-1) cout << endl;
            }
        } else cout << "No solution.";
        cout << endl;
        if (i != N - 1) cout << endl;
    }
 
    return 0;
}