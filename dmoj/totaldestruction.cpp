// Problem ID: totaldestruction
// By Alexander Cai
// Solved 3 Jan 2020

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;
    int capsules[N+5], v;
    memset(capsules, 0, sizeof(capsules));

    for (int i = 0; i < Q; i++)
        cin >> v, capsules[v]++;

    int total = 0, last = 1;
    vector<int> dist;
    for (int i = 1; i <= N; i++)
    {
        if (capsules[i] == 0 && capsules[i-1] > 0)
            last = i;
        else if (capsules[i] > 0 && capsules[i-1] == 0)
            dist.push_back(i - last);
        if (capsules[i] > 0)
            total++;
    }
    dist.erase(dist.begin());
    if (dist.empty())
    {
        cout << total << '\n';
        return 0;
    }

    sort(dist.begin(), dist.end());
    
    for (int i = 0; i < dist.size()+1-M; i++)
        total += dist[i];

    cout << total << '\n';

    return 0;
}
