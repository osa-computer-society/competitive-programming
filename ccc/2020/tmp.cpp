#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
vector<int> suffix_array(const T &s)
{
    int n = (int)s.size();
    vector<int> a(n);
    if (n == 0)
    {
        return a;
    }

    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&s](int i, int j) { return s[i] < s[j]; });
    vector<int> group(n);
    group[a[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
    }
    int cnt = group[a[n - 1]] + 1;
    int step = 1;
    while (cnt < n)
    {
        vector<int> by_second;
        for (int i = n - step; i < n; i++)
            by_second.push_back(i);
        for (int i = 0; i < n; i++)
            if (a[i] - step >= 0)
                by_second.push_back(a[i] - step);

        vector<int> ptr(cnt);
        for (int i = n - 1; i >= 0; i--)
            ptr[group[a[i]]] = i;

        for (int x : by_second)
            a[ptr[group[x]]++] = x;

        vector<int> new_group(n);
        new_group[a[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            int add = 1;
            if (group[a[i]] == group[a[i - 1]])
            {
                int pre = (a[i - 1] + step >= n ? -1 : group[a[i - 1] + step]);
                int cur = (a[i] + step >= n ? -1 : group[a[i] + step]);
                if (pre == cur)
                {
                    add = 0;
                }
            }
            new_group[a[i]] = new_group[a[i - 1]] + add;
        }
        swap(group, new_group);
        cnt = group[a[n - 1]] + 1;
        step <<= 1;
    }
    return a;
}

template <typename T>
vector<int> find_lcp(const T &s, const vector<int> &sa)
{
    int n = (int)s.size();
    assert((int)sa.size() == n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        pos[sa[i]] = i;
    }
    vector<int> lcp(max(n - 1, 0));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k - 1, 0);
        if (pos[i] == n - 1)
        {
            k = 0;
        }
        else
        {
            int j = sa[pos[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
            {
                k++;
            }
            lcp[pos[i]] = k;
        }
    }
    return lcp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string w, s;
    cin >> w >> s;
    int n = s.size();
    int m = w.size();
    vector<int> wcnt(26, 0);

    for (char c : w)
        wcnt[c - 'a']++;

    vector<int> cnt(26, 0);
    for (int i = 0; i < m; i++)
        cnt[s[i] - 'a']++;

    vector<int> res;
    for (int i = 0; i <= n - m; i++)
    {
        if (cnt == wcnt)
            res.push_back(i);
        cnt[s[i] - 'a']--;
        if (i + m == n)
            break;
        cnt[s[i + m] - 'a']++;
    }

    vector<int> sa = suffix_array(s);
    vector<int> lcp = find_lcp(s, sa);
    vector<int> pos(n);

    for (int i = 0; i < n; i++)
        pos[sa[i]] = i;
    for (int i = 0; i < (int)res.size(); i++)
        res[i] = pos[res[i]];

    sort(res.begin(), res.end());
    if (res.empty())
    {
        cout << "0\n";
        return 0;
    }

    int ans = 1;
    for (int i = 1; i < (int)res.size(); i++)
    {
        int mn = n;
        for (int j = res[i - 1]; j < res[i]; j++)
            mn = min(mn, lcp[j]);
        if (mn < m)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}