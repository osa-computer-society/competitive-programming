// solved

#include <fstream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("camelot.in");
ofstream fout("camelot.out");

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dist[35][30][35][30];
pii knights[30 * 35];
pii king;
int nknights = 0;

int R, C;
queue<pii> q;

// typical breadth first search
void bfs(int sr, int sc)
{
    dist[sr][sc][sr][sc] = 0;
    q.push(make_pair(sr, sc));
    while (!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nr = r + dr[i], nc = c + dc[i];
            // if we haven't seen a square yet
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && dist[sr][sc][nr][nc] > 1e5)
            {
                q.push(make_pair(nr, nc));
                dist[sr][sc][nr][nc] = dist[sr][sc][r][c] + 1;
            }
        }
    }
}

int main()
{
    memset(dist, 0x3f, sizeof dist);

    fin >> R >> C;

    char col;
    int row;
    fin >> col >> row;
    king = make_pair(row - 1, col - 'A');

    while (fin >> col >> row)
        knights[nknights++] = make_pair(row - 1, col - 'A');

    if (nknights == 0) // ensure there is at least one knight n
    {
        fout << 0 << '\n';
        fin.close();
        fout.close();
        return 0;
    }

    for (int sr = 0; sr < R; sr++)
        for (int sc = 0; sc < C; sc++)
            bfs(sr, sc);

    int ans = 0x3f3f3f3f; // minimum required distance
    // for every destination square
    for (int destr = 0; destr < R; ++destr)
    {
        for (int destc = 0; destc < C; ++destc)
        {
            int total = 0;
            bool ok = true;
            // for each knight, if it can reach the destination, add the distance to total
            // otherwise break
            for (int i = 0; i < nknights; ++i)
            {
                int kr = knights[i].first, kc = knights[i].second;
                if (dist[destr][destc][kr][kc] < 1e5)
                    total += dist[destr][destc][kr][kc];
                else
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;

            // check each square the knight and king might meet each other
            // must be within 2 squares of the king, otherwise it can be crossed by a single knight move
            for (int meetr = max(king.first - 2, 0); meetr <= min(king.first + 2, R - 1); ++meetr)
            {
                for (int meetc = max(king.second - 2, 0); meetc <= min(king.second + 2, C - 1); ++meetc)
                {
                    // make sure knight path from meet to destination
                    if (dist[destr][destc][meetr][meetc] < 1e5)
                    {
                        for (int i = 0; i < nknights; ++i)
                        {
                            int kr = knights[i].first, kc = knights[i].second;
                            if (dist[meetr][meetc][kr][kc] < 1e5 && dist[destr][destc][kr][kc] < 1e5)
                                ans = min(ans, total - dist[destr][destc][kr][kc] + max(abs(meetr - king.first), abs(meetc - king.second)) + dist[meetr][meetc][kr][kc] + dist[destr][destc][meetr][meetc]);
                        }
                    }
                }
            }
        }
    }

    fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
