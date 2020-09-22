#include <iostream>
using namespace std;

int x[105];

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, A, B, C;
        cin >> N >> A >> B >> C;

        int tot = A + B - C;
        int i, cnt;

        if (tot > N)
        {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }

        if (N == 1)
        {
            cout << "Case #" << t << ": 1\n";
            continue;
        }

        for(i = 1; i <= N; ++i)
            x[i] = 0;

        for (i = 1; i <= A - C; ++i)
            x[i] = N-A+C-1+i; // A's
        for (i = N, cnt = 1; cnt <= B - C; --i, ++cnt)
            x[i] = N-B+C-1+cnt; // B's

        if (C > 1)
        {
            x[A - C + 1] = N;
            for (i = A - C + 2, cnt = 1; cnt <= N - tot; ++i, ++cnt)
                x[i] = 1;
            for (cnt = 1; cnt <= C - 1; ++i, ++cnt)
                x[i] = N;
        }
        else if (A > C)
        {
            x[N] = N;
            for (i = A - C + 1, cnt = 1; cnt <= N - tot; ++i, ++cnt)
                x[i] = 1;
        }
        else if (B > C)
        {
            x[1] = N;
            for (i = N - (B - C), cnt = 1; cnt <= N - tot; --i, ++cnt)
                x[i] = 1;
        }
        else // A == B == C == 1 < N
        {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }

        cout << "Case #" << t << ":";
        for (i = 1; i <= N; ++i)
            cout << ' ' << x[i];
        cout << '\n';
    }
    return 0;
}