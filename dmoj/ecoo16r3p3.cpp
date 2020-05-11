// Problem ID: ecoo16r3p3.cpp
// By Alexander Cai

#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cstring>
#define MAXLEN 2005
#define INF 0x3f3f3f3f
using namespace std;

int dp[MAXLEN];
string str;
set<string> dict;

int recurse(int idx)
{
    if (idx == str.size()) return 0;
    if (dp[idx] > -1) return dp[idx];
    stringstream ss;
    int ans = INF;
    for (int i = idx; i < str.size(); ++i)
    {
        ss << str[i];
        if (dict.count(ss.str())) ans = min(ans, recurse(i+1) + 1);
    }
    return dp[idx] = ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> str;
        dict.insert(str);
    }

    for (int i = 1; i <= 10; ++i)
    {
        memset(dp, -1, sizeof(dp));
        cin >> str;
        cout << recurse(0)-1 << '\n';
    }

    return 0;
}
