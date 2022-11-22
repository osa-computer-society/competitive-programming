#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int dx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
int dist[9][9];

int main()
{
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;

    queue<pii> Q;
    Q.push({sx, sy});
    while (!Q.empty())
    {
        pii u = Q.front();
        Q.pop();

        if (u.first == fx && u.second == fy)
        {
            cout << dist[fx][fy] << '\n';
            return 0;
        }

        for (int i = 1; i <= 8; ++i)
        {
            int nx = u.first + dx[i], ny = u.second + dy[i];

            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) // if it's within bounds
            {
                dist[nx][ny] = dist[u.first][u.second] + 1;
                Q.push({nx, ny});
            }
        }
    }

    return 0;
}