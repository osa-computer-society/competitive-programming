#include <iostream>
#include <vector>
#include <string>
#define TEST
using namespace std;

vector<vector<string> > rules;

struct Node
{
    int rulenum;
    int startind;
    string val;
};

int main() {
    for (int i = 0; i < 3; i++) { // We load in the rules
        vector<string> rule{};
        string s;

        cin >> s;
        rule.push_back(s);
        cin >> s;
        rule.push_back(s);

        rules.push_back(rule);
    }

    int s; string i, f;
    cin >> s >> i >> f;

    #ifdef TEST
    cout << endl;
    for (vector<string> rule : rules) {
        for (string temp : rule) {
            cout << temp << " ";
        }
        cout << endl;
    }
    #endif
}