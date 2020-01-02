// Problem ID: 
// By 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int a = s.find('A');
    int b = s.rfind('Z');
    cout << b - a + 1 << '\n';

    return 0;
}
