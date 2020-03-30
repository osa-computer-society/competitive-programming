// Problem ID: ccc20practice3.cpp
// By 

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

pii freq[1005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0, t; i < N; i++)
        cin >> t, freq[t].first++, freq[t].second = t;
    
    sort(freq, freq+1005, greater<pii>());
    
    if (freq[0].first == freq[1].first)
    {
        int ans = -0x3f3f3f3f;
        for (int j = 1; j < N && freq[j].first==freq[0].first; j++)
            ans = max(ans, abs(freq[0].second - freq[j].second));
        cout << ans << '\n';
        return 0;
    }
    if (freq[1].first != freq[2].first)
    {
        cout << abs(freq[0].second - freq[1].second) << '\n';
        return 0;
    }
    int ans = -0x3f3f3f3f;
    for (int j = 1; j < N && freq[j].first==freq[1].first; j++)
        ans = max(ans, abs(freq[0].second - freq[j].second));
    cout << ans << '\n';

    return 0;
}
