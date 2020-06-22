// Problem ID: pacnw16a.cpp
// By Alexander Cai

#include <iostream>
#include <string>
using namespace std;

int dp[52];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    int N = S.size();
    int best;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        best = 0;
        for (int j = 1; j < i; ++j)
        {
            if ((char)S[j-1] < (char)S[i-1])
                best = max(best, dp[j]);
        }
        dp[i] = best + 1;
    }

    int ans = -1;
    for (int i = 1; i <= N; ++i) ans = max(ans, dp[i]);
    cout << 26 - ans << '\n';

    return 0;
}
