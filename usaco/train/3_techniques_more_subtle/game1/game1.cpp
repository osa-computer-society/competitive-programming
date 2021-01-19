// solved

#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("game1.in");
ofstream fout("game1.out");

int dp[205][205];
int psa[205];
int a, b;

int main()
{
    int N;
    fin >> N;
    for (int i = 1; i <= N; ++i)
        fin >> dp[i][i], psa[i] = psa[i - 1] + dp[i][i];

    for (int i = 1; i <= N; ++i)
        for (int l = 1; l + i <= N; ++l)
            dp[l][l + i] = psa[l + i] - psa[l - 1] - min(dp[l + 1][l + i], dp[l][l + i - 1]);

    fout << dp[1][N] << ' ' << psa[N] - dp[1][N] << '\n';

    fin.close();
    fout.close();
    return 0;
}
