// Problem ID: oly20practice30.cpp
// By 

#include <iostream>
#include <string>
using namespace std;

const char L = 1, R = 2;
char s[2001];
char dp[2001][2001];

void recurse(int l, int r) {
    if (l > r) return dp[l][r] = L;
    if (dp[l][r]) return dp[l][r];

    if (s[l] < s[r]) {
        dp[l][r] = L;
        recurse(l+1, r);
    } else if (s[l] > s[r]) {
        dp[l][r] = R;
        recurse(l, r-1);
    } else { // s[l] == s[r]
        if (recurse(l+1, r) < recurse(l, r-1)) dp[l][r] = L;
        else dp[l][r] = R;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> s[i];

    int l = 1, r = N;
    recurse(l, r);
    while (l <= r) {
        if (dp[l][r] == L) {
            cout << s[l];
            l++;
        } else {
            cout << s[r];
            r--;
        }
    }
    cout << '\n';

    return 0;
}
