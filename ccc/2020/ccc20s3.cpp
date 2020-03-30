// Problem ID: ccc20s3.cpp
// By 

#include <iostream>
#include <string>
#include <set>
using namespace std;

long long ncnt[30], hcnt[30];
set<string> perms;

bool works()
{
    for (int j = 0; j < 26; j++)
        if (ncnt[j] != hcnt[j])
            return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string N, H;
    cin >> N >> H;

    long long n = N.size(), h = H.size();

    if (n > h)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++)
        ncnt[N[i]-'a']++, hcnt[H[i]-'a']++;

    if (works()) perms.insert(H.substr(0, n));
    
    for (int i = n+1; i <= h; i++)
    {
        hcnt[H[i-1-n]-'a']--;
        hcnt[H[i-1]-'a']++;
        if (works())
          perms.insert(H.substr(i-n, n));
    }

    cout << perms.size() << '\n';
    
    return 0;
}
