// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits>
#define MAXN 300005
using namespace std;

const int INF = numeric_limits<int>::max();

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> adj[N+5];
    int amt[N+5];

    for (int i = 0; i < M; i++)
    {
        int target, n, t;
        cin >> target >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            adj[target-1].push_back(t-1);
        }
    }

    int t;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        amt[i] = t;
    }

    int min = INF;
    int dist[N];
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[0] = amt[0];
    queue<int> Q;
    Q.push(0);

    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        if (adj[u].empty() && dist[u] < min) min = dist[u]; // is leaf
        else for (int v : adj[u])
        {
            dist[v] = dist[u] + amt[v];
            Q.push(v);
        }
    }

    cout << min << '\n';

    return 0;
}
