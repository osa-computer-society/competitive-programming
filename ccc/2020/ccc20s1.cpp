// Problem ID: ccc20s1.cpp
// By 

#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef pair<int,int> pii;
typedef long double ld;
pii x[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> x[i].first >> x[i].second;

    sort(x+1, x+N+1);

    ld maxs = -(9*1e18);
    for (int i = 2; i <= N; i++)
    {
        ld val = (long double)(x[i].second-x[i-1].second)/(long double)(x[i].first-x[i-1].first);
        if (val < 0) val = -val;
        maxs = max(maxs, val);
    }
    
    cout << fixed << setprecision(10) << maxs << '\n';

    return 0;
}
