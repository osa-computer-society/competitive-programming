// Problem ID: ccc20s4.cpp
// By 

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int N = s.size();

    int a = 1, b = 1, c = 1;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'A') b = b%N+1, c = c%N+1;
        if (s[i] == 'B') c = c%N+1;
    }

    // cout << a << " " << b << " " << c << '\n';

    // cout << s << '\n';

    ll cnt = 0, ans = 9*1e18;
    for (int i = a; i != b; i=i%N+1) if (s[i-1] != 'A') cnt++;
    for (int i = b; i != c; i=i%N+1) if (s[i-1] != 'B') cnt++;
    for (int i = c; i != 1; i=i%N+1) if (s[i-1] != 'C') cnt++;

    ans = min(ans, (ll)ceil(cnt/2.0));

    for (int i = 1; i <= N; i++)
    {
        if (s[a-1] == 'A') cnt++;
        if (s[b-1] == 'B') cnt++;
        if (s[c-1] == 'C') cnt++;
        
        if (s[b-1] == 'A') cnt--;
        if (s[c-1] == 'B') cnt--;
        if (s[a-1] == 'C') cnt--;

        a = a%N + 1;
        b = b%N + 1;
        c = c%N + 1;
        // cout << a << '\t' << b << '\t' << c << '\t' << cnt << '\t' << ceil(cnt/2.0) << '\n';
        ans = min(ans, (ll)ceil(cnt/2.0));
    }

    cout << ans << '\n';

    return 0;
}
