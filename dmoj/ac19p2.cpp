// Problem ID: ac19p2.cpp
// By 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    cin.ignore();
    string s;
    getline(cin, s);
    for (int i = 0; i < N; i++)
    {
        if (s[i] == ' ') { cout << ' '; continue; }
        cout << (char) (((s[i]-'a') + L) % 26 + 'a');
    }
    cout << "\n";

    return 0;
}
