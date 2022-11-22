// Problem ID:
// By Alexander Cai

#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2005;
int x[maxn], y[maxn], z[maxn];

vector<pii> twos, ones;

vector<int> factors[17];

bool cmp(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    FOR(i, 1, M)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    FOR(i, 1, M)
    {
        if (z[i] == 1)
            ones.push_back({x[i], y[i]});
        if (z[i] == 2)
            twos.push_back({x[i], y[i]});
    }

    sort(twos.begin(), twos.end(), cmp);
    sort(ones.begin(), ones.end(), cmp);

    int last = -1;
    for (int i = twos.size() - 1; i > 0; --i)
    {
        if (twos[i].first <= twos[i - 1].second + 1)
        {
            twos[i - 1].first = min(twos[i - 1].first, twos[i].first);
            twos[i - 1].second = twos[i].second;
            twos.erase(twos.begin() + i);
        }
    }

    for (pii one : ones)
    {
        for (pii two : twos)
        {
            if (one.first >= two.first && one.second <= two.second)
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    FOR(i, 1, N)
    {
        bool istwo = false;
        for (pii two : twos)
        {
            if (i >= two.first && i <= two.second)
            {
                cout << "2 ";
                istwo = true;
                break;
            }
        }
        if (!istwo)
            cout << "1 ";
    }
    cout << '\n';

    return 0;
}
