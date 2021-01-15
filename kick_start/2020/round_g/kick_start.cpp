// Solved

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int nkicks = 0;
        int ans = 0;
        string s;
        cin >> s;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (s.substr(i, 4) == "KICK") // matched "KICK"
                ++nkicks;
            if (s.substr(i, 5) == "START") // matched "START"
                ans += nkicks;
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
