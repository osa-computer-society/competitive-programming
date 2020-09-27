// unfinished

#include <iostream>
#include <fstream>
#include <cstring>
#define MAXS 7
using namespace std;

int c;
bool blocked[MAXS][3 * MAXS];

int S;

int score(int ra, int pa, int rb, int pb, bool turn, int cur, bool prevblocked);

// returns true if the next state is blocked or invalid
// returns false if that is a valid move
bool update(int *ans, int ra, int pa, int rb, int pb, bool turn, int cur, bool prevblocked)
{
    // the next tile to be painted
    int r = turn ? rb : ra, p = turn ? pb : pa;
    if (r < 1 || r > S || p < 1 || p > 2 * r - 1 || blocked[r][p])
        return true;
    blocked[r][p] = true; // paint the next tile
    if (turn) // B's turn, minimize
        *ans = min(*ans, score(ra, pa, rb, pb, !turn, cur - 1, prevblocked));
    else // A's turn, maximise
        *ans = max(*ans, score(ra, pa, rb, pb, !turn, cur + 1, prevblocked));
    blocked[r][p] = false; // unpaint tile for recursion
    return false;
}

// State in the game can be defined by:
// 1. The free rooms.
// 2. Position of Alma.
// 3. Position of Berthe.
// 4. Whose turn is it? (0 = A, 1 = B)
// 5. Present score of the game
// If turn == 0, we want to return the maximum possible score, else minimum
int score(int ra, int pa, int rb, int pb, bool turn, int cur, bool prevblocked)
{
    int ans = cur;

    // if the position of the current player's tile is odd, we can check below
    // them, otherwise we check above them
    // B's turn
    if (turn)
    {
        bool allblocked = true;
        if (pb & 1)
            allblocked = update(&ans, ra, pa, rb + 1, pb + 1, turn, cur, false) && allblocked;
        else
            allblocked = update(&ans, ra, pa, rb - 1, pb - 1, turn, cur, false) && allblocked;
        allblocked = update(&ans, ra, pa, rb, pb - 1, turn, cur, false) && allblocked;
        allblocked = update(&ans, ra, pa, rb, pb + 1, turn, cur, false) && allblocked;
        if (allblocked && !prevblocked)
            ans = score(ra, pa, rb, pb, !turn, cur, true); // B can't move so now it's A's turn
    }
    else // A's turn
    {
        bool allblocked = true;
        if (pa & 1)
            allblocked = update(&ans, ra + 1, pa + 1, rb, pb, turn, cur, false) && allblocked;
        else
            allblocked = update(&ans, ra - 1, pa - 1, rb, pb, turn, cur, false) && allblocked;
        allblocked = update(&ans, ra, pa - 1, rb, pb, turn, cur, false) && allblocked;
        allblocked = update(&ans, ra, pa + 1, rb, pb, turn, cur, false) && allblocked;
        if (allblocked && !prevblocked)
            ans = score(ra, pa, rb, pb, !turn, cur, true);
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    // number of blocked rooms, a's position, b's position, blocked positions
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
        blocked[ra][pa] = blocked[rb][pb] = true;
        cout << "Case #" << t << ": " << score(ra, pa, rb, pb, 0, 0, false) << '\n';
    }

    return 0;
}
