#include <iostream>
#include <string>
using namespace std;

int freqa[26];
int freqb[26];
int nstar;

int main()
{
    string a, b;

    cin >> a >> b;

    for (char c : a)
    {
        freqa[c - 'a']++;
    }
    for (char c : b)
    {
        if (c == '*')
            nstar++;
        else
            freqb[c - 'a']++;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (freqa[i] >= freqb[i])
        {
            nstar -= freqa[i] - freqb[i];
        }
        else
        {
            cout << "N\n";
            return 0;
        }
    }

    cout << "A\n";

    return 0;
}
