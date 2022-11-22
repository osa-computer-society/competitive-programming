// Problem ID:
// By Alexander Cai

#include <iostream>
#include <vector>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

vector<double> flow;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    flow.resize(N + 1);

    FOR(i, 1, N)
    {
        cin >> flow[i];
    }

    int n;
    while (true)
    {
        cin >> n;
        if (n == 99)
        {
            // split
            int k;
            cin >> k;
            double perc;
            cin >> perc;
            double l = flow[k] * perc / 100;
            flow.insert(flow.begin() + k + 1, flow[k] - l);
            flow[k] = l;
        }
        else if (n == 88)
        {
            // join
            int k;
            cin >> k;
            flow[k] = flow[k] + flow[k + 1];
            flow.erase(flow.begin() + k + 1);
        }
        else if (n == 77)
        {
            break;
        }
    }

    FOR(k, 1, flow.size() - 1)
    cout << flow[k] << ' ';
    cout << '\n';

    return 0;
}
