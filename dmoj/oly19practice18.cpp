// Problem ID: oly19practice18.cpp
// By Alexander Cai

#include <iostream>
#include <string>
using namespace std;

int dp[302][302];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int N = s.size();

    for (int i = 1; i <= N; ++i)
    {
        dp[i][i] = 1;
    }

    return 0;
}
