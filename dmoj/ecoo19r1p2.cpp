// Problem ID: ecoo19r1p2.cpp
// By Alexander Cai

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int K = 10;

int first[27], last[27], rules[27][27], cnt[2][27];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int R, T, ans, f, l;
    string A, s;
    char c;

    while (K--)
    {
        memset(first, 0, sizeof(first));
        memset(last, 0, sizeof(last));
        memset(rules, 0, sizeof(rules));
        memset(cnt, 0, sizeof(cnt));

        cin >> R >> T >> A;
        for (int i = 1; i <= R; ++i)
        {
            cin >> c >> s;
            for (char cc : s) rules[c-'A'][cc-'A']++;
            first[c-'A'] = (char)s[0]-'A';
            last[c-'A'] = (char)s[s.size()-1]-'A';
        }

        for (char cc : A) cnt[T&1][cc-'A']++;
        f = (char)A[0]-'A', l = (char)A[A.size()-1]-'A';
        
        while (T--)
        {
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    cnt[T&1][j] += cnt[~T&1][i] * rules[i][j];
            memset(cnt[~T&1], 0, sizeof(cnt[~T&1]));
            f = first[f], l = last[l];
        }

        ans = 0;
        for (int i = 0; i < 26; i++) ans += cnt[0][i];
        cout << (char)(f+'A') << (char)(l+'A') << ' ' << ans << '\n';
    }

    return 0;
}
