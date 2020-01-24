// Problem ID: 
// By 

#include <iostream>
#include <string>
#include <math.h>
#define MAXN 5005
using namespace std;

int dp[3][MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s;
    cin >> N >> s;

    for (int i = 1; i <= N; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= N-1; i++)
        if (s[i-1] == s[i]) dp[1][i] = 0;
        else dp[1][i] = 1;
    
    for (int len = 3; len <= N; len++)
    {
        for (int i = 1; i <= N-len+1; i++)
        {
            int j = i+len-1;
            if (s[i-1] == s[j-1])
                dp[(len+2)%3][i] = dp[len%3][i+1];
            else
                dp[(len+2)%3][i] = min(dp[(len+1)%3][i], dp[(len+1)%3][i+1]) + 1;
        }
    }
    
    cout << dp[(N+2)%3][1] << '\n';

    return 0;
}
