// Probdpem ID:
// By
#include <iostream>
#include <string>
#include <cstring>
#define L 0
#define U 1
#define D 2
using namespace std;

int dp[3002][3002];
int dir[3002][3002];

int main()
{
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i-1][j-1] + 1, dir[i][j] = D;
            else
            {
                if (dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j], dir[i][j] = L;
                else
                    dp[i][j] = dp[i][j-1], dir[i][j] = U;
            }
        }
    }

    string ans = "";
    while (m > 0 && n > 0)
    {
        if (dir[m][n] == D)
        {
            ans = s[m-1] + ans;
            m--, n--;
        }
        else if (dir[m][n] == L) m--;
        else if (dir[m][n] == U) n--;
    }
    cout << ans << '\n';
    return 0;
}
