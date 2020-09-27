// Problem ID: 
// By 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    string s;
    int clen = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (clen == 0)
            cout << s, clen = s.size();
        else if (clen + s.size() > K)
        {
            cout << '\n' << s;
            clen = s.size();
        }
        else
            cout << ' ' << s, clen += s.size();
    }
    cout << '\n';

    return 0;
}
