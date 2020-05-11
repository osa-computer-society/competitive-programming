#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
 
int N, M;
 
vector<pll> intervals;
 
bool works(ll d)
{
    ll prev = -INF;
    
    int cnt = 0;
    for (pll i : intervals)
    {
        while (max(prev + d, i.first) <= i.second)
        {
            prev = max(prev + d, i.first);
            cnt++;
            if (cnt >= N) break;
        }
        if (cnt >= N) break;
    }
 
    return cnt >= N;
}
 
int main()
{
    cin >> N >> M;

    intervals.resize(M);

    for (int i = 0; i < M; ++i) 
        cin >> intervals[i].first >> intervals[i].second;
 
    sort(intervals.begin(), intervals.end());
 
    ll lo = 1;
    ll hi = INF;
    ll ans = -1;
 
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (works(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
 
    cout << ans << '\n';
}