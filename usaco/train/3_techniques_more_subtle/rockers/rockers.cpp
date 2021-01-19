// solved

// dynamic programming
// 0-1 knapsack

#include <fstream>
using namespace std;

ifstream fin("rockers.in");
ofstream fout("rockers.out");

int songlen[25];
// dp[a][b][c] = # songs on first a cds with b minutes used on the ath cd and c being the last song on cd a
int dp[25][25][25];

int main()
{
    int nsongs, disklen, ndisks;
    fin >> nsongs >> disklen >> ndisks;

    for (int i = 1; i <= nsongs; ++i)
        fin >> songlen[i];

    int ans = -1;
    for (int a = 0; a < ndisks; ++a) // number of cds we consider
    {
        for (int b = 0; b <= disklen; ++b) // amount of time taken on ath cd
        {
            for (int c = 0; c <= nsongs; ++c) // last song on ath cd
            {
                for (int d = c + 1; d <= nsongs; ++d) // for each remaining possible song
                {
                    if (b + songlen[d] <= disklen) // if we can fit it on disk a
                    {
                        // check if it is better to include or not
                        int &k = dp[a][b + songlen[d]][d];
                        k = max(k, dp[a][b][c] + 1);
                    }
                    else // can't fit on disk a, put on next disk?
                    {
                        int &k = dp[a + 1][songlen[d]][d];
                        k = max(k, dp[a][b][c] + 1);
                    }
                }
                ans = max(ans, dp[a][b][c]);
            }
        }
    }

    fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
