// Problem ID: 
// By 

#include <iostream>
#include <string>
#define MAXN 205
using namespace std;

int dp[MAXN][MAXN];

bool isl(char c)
{
    return c == '(' || c == '[' || c == '{';
}
bool isr(char c)
{
    return c == ')' || c == ']' || c == '}';
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s;
    cin >> N >> s;

    for (int i = 1; i <= N-1; i++)
    {
        if ((is_bracket(s[i-1]) && s[i] == '?') || (s[i-1] == '?' && is_bracket(s[i])))
            dp[i][i+1] = 1;
        else if (s[i-1] == '?' && s[i] == '?')
            dp[i][i+1] = 3;
        else
            dp[i][i+1] = 0;
    }

    for (int len = 4; len <= N; len += 2)
    {
        for (int i = 1; i <= N-len+1; i++)
        {
            int j = i+len-1;
            if (isl(s[i-1]) && s[i-1] == s[j-1])
                dp[i][j] = dp[i+1][j-1];
            if ((is_bracket(s[i-1]) && s[j-1] == '?') || (s[i-1] == '?' && is_bracket(s[j-1])))
                dp[i][j] = max(dp[i+1][j-1], dp[j]);

            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }

    return 0;
}
