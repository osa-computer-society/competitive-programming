// Problem ID: waterloow2017b
// By 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int freq[30], used[30];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    string A;
    cin >> N >> K >> A;

    if (N == K)
    {
        cout << A << '\n';
        return 0;
    }
    else if (K > N)
    {
        cout << "WRONGANSWER\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
        freq[A[i]-'a']++;

    vector<pii> Q;

    for (int i = 0; i < 26; i++)
        Q.push_back({freq[i], i});
    
    sort(Q.begin(), Q.end());

    if (K < Q[0].first)
    {
        cout << "WRONGANSWER\n";
        return 0;
    }

    int lcs = 0, curr = 0;
    while (lcs < K)
    {
        int f = Q[curr].first, i = Q[curr].second;
        if (lcs + f <= K)
            lcs += f, used[i] += f;
        else
            used[i] += K-lcs, lcs = K;
        curr++;
    }

    string ans = "";
    
    for (int i = 0; i < N; i++)
        if (used[A[i]-'a'] > 0)
            ans += A[i], used[A[i]-'a']--;
    
    while (ans.size() < N)
        ans += (char)(Q[0].second+'a');

    cout << ans << '\n';

    return 0;
}
