// Problem ID: 
// By 

#include <iostream>
#include <string>
using namespace std;

int cnt[100005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int Q;
    cin >> Q;

    int c = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i-1] == 'G')
            c++;
        cnt[i] = c;
    }
    
    for (int i = 0, a, b; i < Q; i++)
    {
        cin >> a >> b;
        cout << cnt[b+1] - cnt[a] << '\n';
    }

    return 0;
}
