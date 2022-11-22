// By Alexander Cai 2021-02-14

#include <iostream>
#include <string>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int maxn = 3005;

// dp[i][j] = length of longest subsequence from s[1..i] and t[1..j]
int dp[maxn][maxn];
string s, t;

void backtrack(int, int);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    int N = s.size(), M = t.size();

    FOR(i, 1, N)
    {
        FOR(j, 1, M)
        {
            // if the ith char of s and the jth char of t match,
            // the length of LCS of s[1..i] and t[1..j]
            // is 1 more than the length of LCS of s[1..i-1] and t[1..j-1]
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            // if they don't match, then the length of LCS of s[1..i] and t[1..j]
            // is whichever is greater:
            // len of LCS of s[1..i] and t[1..j-1] or s[1..i-1] and t[1..j]
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    backtrack(N, M); // prints the characters while recursing
    cout << '\n';

    return 0;
}

void backtrack(int i, int j)
{
    if (i > 0 && j > 0)
    {
        // we print a character if they match at that point
        if (s[i - 1] == t[j - 1])
        {
            backtrack(i - 1, j - 1);
            cout << s[i - 1];
        }
        else if (dp[i][j] == dp[i][j - 1])
            backtrack(i, j - 1); // decrement slice of t
        else
            backtrack(i - 1, j); // decrement slice of s
    }
}
