// solved

// deque, data structure

#include <iostream>
#include <deque>
using namespace std;

deque<int> buildings;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, A, B, C;
        cin >> N >> A >> B >> C;
        int tot = A + B - C;
        int extra = N-tot;
        if (extra < 0)
        {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }

        buildings.clear();
        for (int i = 1; i <= C; i++)
            buildings.push_back(N);

        if (extra > 0)
        {
            if (C > 1)
            {
                buildings.pop_back();
                for (int i = 0; i < extra; i++)
                    buildings.push_back(1);
                buildings.push_back(N);
            }
            else if (A > C)
                for (int i = 0; i < extra; i++)
                    buildings.push_front(1);
            else if (B > C)
                for (int i = 0; i < extra; i++)
                    buildings.push_back(1);
            else
            {
                cout << "Case #" << t << ": IMPOSSIBLE\n";
                continue;
            }
        }

        for (int i = 1, cnt = N-1; i <= B-C; i++, cnt--)
            buildings.push_back(cnt);
        for (int i = 1; i <= A-C; i++)
            buildings.push_front(N-i);

        cout << "Case #" << t << ":";
        for (int i = 0; i < buildings.size(); i++) cout << ' ' << buildings[i];
        cout << '\n';
    }
    return 0;
}