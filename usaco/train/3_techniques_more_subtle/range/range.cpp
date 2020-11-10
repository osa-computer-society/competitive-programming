// home on the range

// solved
// dynamic programming
// 2D array

#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("range.in");
ofstream fout("range.out");

bool dp[2][255][255];

int main()
{
    int N;
    fin >> N;

    char b;
    for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c)
            fin >> b, dp[1][r][c] = b - '0';

    for (int i = 2; i <= N; ++i)
    {
        int total = 0;
        for (int r = 1; r <= N - i + 1; ++r)
        {
            for (int c = 1; c <= N - i + 1; ++c)
            {
                dp[i & 1][r][c] = dp[~i & 1][r][c] && dp[~i & 1][r + 1][c] && dp[~i & 1][r][c + 1] && dp[~i & 1][r + 1][c + 1];
                if (dp[i & 1][r][c])
                    ++total;
            }
        }
        if (total == 0)
            break;
        fout << i << ' ' << total << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
