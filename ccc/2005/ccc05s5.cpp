// Problem ID: 
// By 

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#define MAXN 100005
using namespace std;
typedef pair<int,int> pii;

pii x[MAXN];
int bit[MAXN], p[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> x[i].first, x[i].second = i;
    sort(x+1, x+N+1);
    for (int i = 1; i <= N; i++)
        p[x[i].second] = N-i+1;

    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int t = p[i];
        for (; t > 0; t -= (t&-t))
            ans += bit[t];
        t = p[i];
        for (; t <= N; t += (t&-t))
            bit[t]++;
    }

    cout << fixed << setprecision(2) << (ans+N)/(float)N << '\n';

    return 0;
}
