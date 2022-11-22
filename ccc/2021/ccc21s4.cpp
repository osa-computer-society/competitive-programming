// Problem ID:
// By Alexander Cai

#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2005;
vector<int> adj[maxn];
int train[maxn];
unordered_map<int, bool> vis;
queue<pii> Q;

int N, W, D;

void visit(int v, int t)
{
    int hash = t * (N + 1) + v;
    if (vis[hash])
        return;
    Q.push({v, t});
    vis[hash] = true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W >> D;

    // walking trails
    int a, b;
    FOR(i, 1, W)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // train
    FOR(i, 1, N)
    cin >> train[i];

    int p, q;
    FOR(d, 1, D)
    {
        // swap positions
        cin >> p >> q;
        int tmp = train[p];
        train[p] = train[q];
        train[q] = tmp;

        // clear
        while (!Q.empty())
            Q.pop();
        vis.clear();
        visit(1, 1);
        while (!Q.empty())
        {
            int u = Q.front().first;
            int t = Q.front().second;
            Q.pop();

            if (u == N)
            {
                cout << t - 1 << '\n';
                break;
            }

            for (int v : adj[u])
                if (v != train[t + 1])
                    visit(v, t + 1);
            visit(train[t + 1], t + 1);
            visit(u, t + 1);
        }
    }

    return 0;
}
