#include <iostream>
#include <string>
#define MAXN 200005

using namespace std;

int dp[MAXN][MAXN];

int minimumTime(string s) {
    
}

int recur(string s, int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int ans = 1 + recur(s, l+1, r);
    ans = max(ans, 1 + recur(s, l, r-1));
    
}

int main()
{

    return 0;
}