// This solves test case 1 for a total of 12 points. Since S = 2, It literally
// only requires thinking about 5 relatively simple cases so it's a good example
// of not trying to tackle the full problem and going for partial marks.

#include <iostream>
#include <cstring>
using namespace std;

bool blocked[10][10];

int main()
{
    int T;
    cin >> T;

    int s, ra, pa, rb, pb, c, ca, cb;
    for (int t = 1; t <= T; ++t)
    {
        memset(blocked, 0, sizeof(blocked));
        cin >> s >> ra >> pa >> rb >> pb >> c;
        for (int i = 1; i <= c; ++i)
            cin >> ca >> cb, blocked[ca][cb] = true;

        cout << "Case #" << t << ": ";
        // If both of the rooms that the players aren't occupying are blocked,
        // or f the middle room is blocked, neither will be able to move
        if (c == 2 || blocked[2][2])
            cout << 0;
        // If a player is on 2, 2, they'll paint two rooms (they get stuck in a
        // corner) and the other player can only paint the block they're on
        else if (ra == 2 && pa == 2)
            cout << 1;
        else if (rb == 2 && pb == 2)
            cout << -1;
        // now we know that nobody starts on (2, 2), so if another room is blocked,
        // A takes 2 and B takes 1
        else if (c == 1)
            cout << 1;
        // otherwise, c == 0 and A takes 3 rooms, B takes 1
        else
            cout << 2;

        cout << '\n';
    }

    return 0;
}
