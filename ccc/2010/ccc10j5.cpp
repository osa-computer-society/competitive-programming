#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int dist[8][8];
pii adj[] = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};

void bfs(int sx, int sy)
{
    queue<pii> Q;
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            dist[x][y] = 100;
    dist[sx][sy] = 0;
    Q.push(make_pair(sx, sy));
    while (!Q.empty())
    {
        int u = Q.front().first, v = Q.front().second, uu, vv;
        Q.pop();
        for (int i = 0; i < 8; i++)
        {
            uu = u + adj[i].first;
            vv = v + adj[i].second;
            if (uu >= 0 && uu < 8 && vv >= 0 && vv < 8 && dist[u][v] + 1 < dist[uu][vv])
            {
                dist[uu][vv] = dist[u][v] + 1;
                Q.push(make_pair(uu, vv));
            }
        }
    }
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1-1, y1-1);
    cout << dist[x2-1][y2-1] << '\n';
    return 0;
}