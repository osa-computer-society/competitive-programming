// Problem ID: 
// By 

#include <iostream>
using namespace std;
typedef long long ll;

bool valid(ll N, ll K, ll M, ll X)
{
    ll g = 0;
    while (K > 0 && g < N)
    {
        ll y = (N - g) / X;
        if (y < M)
        {
            ll left = (N-g + M-1) / M;
            return left <= K;
        }
        ll max_match = N - X*y;
        ll ndays = (max_match - g)/y + 1;
        ndays = min(ndays, K);
        g += y*ndays;
        K -= ndays;
    }
    return g >= N;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N, K, M;
    cin >> N >> K >> M;

    ll lo = 1, hi = 1e12;

    while (lo < hi)
    {
        ll mid = (lo+hi+1)/2;

        if (valid(N, K, M, mid)) lo = mid;
        else hi = mid-1;
    }

    cout << lo << '\n';

    return 0;
}
