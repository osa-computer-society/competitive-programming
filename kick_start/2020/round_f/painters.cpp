#include <iostream>
#include <fstream>
#include <cstring>
#define MAXS 7
using namespace std;

bool blocked[MAXS][3 * MAXS];

int S;

bool valid(int r, int p)
{
    return r >= 1 && r <= S && p >= 1 && p <= 2 * r - 1 && !blocked[r][p];
}

int dfs(int ra, int pa, int rb, int pb)
{
    int diff = -0x3f3f3f3f;
    blocked[ra][pa] = true;

    if (pa & 1)
    {
        if (valid(ra + 1, pa + 1))
            diff = max(diff, -dfs(rb, pb, ra + 1, pa + 1) + 1);
    }
    else if (valid(ra - 1, pa - 1))
        diff = max(diff, -dfs(rb, pb, ra - 1, pa - 1) + 1);

    if (valid(ra, pa - 1))
        diff = max(diff, -dfs(rb, pb, ra, pa - 1) + 1);
    if (valid(ra, pa + 1))
        diff = max(diff, -dfs(rb, pb, ra, pa + 1) + 1);

    blocked[ra][pa] = false;

    return diff;
}

int main()
{
    ifstream cin("painters.in");

    int T;
    cin >> T;

    int c, ra, pa, rb, pb, rc, pc;
    for (int t = 1; t <= T; ++t)
    {
        memset(blocked, 0, sizeof(blocked));
        cin >> S >> ra >> pa >> rb >> pb >> c;
        for (int i = 1; i <= c; ++i)
        {
            cin >> rc >> pc;
            blocked[rc][pc] = true;
        }
        cout << "Case #" << t << ": " << dfs(ra, pa, rb, pb) << '\n';
    }

    return 0;
}
