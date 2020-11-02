#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (s.substr(0, 10) =="Simon says")
        {
            s.erase(0, 11);
            cout << s << endl;
        }
    }
}