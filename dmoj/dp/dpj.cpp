// Problem ID: 
// By 

#include <iostream>
#include <iomanip>
#include <cstring>
#define MAXN 305
using namespace std;
typedef long double ld;

ld dp[MAXN][MAXN][MAXN];
int N, cnt[4];

ld recurse(int n1, int n2, int n3)
{
    if (n1 == 0 && n2 == 0 && n3 == 0)
        return 0.0l;

    if (dp[n1][n2][n3] != -1) return dp[n1][n2][n3];
    
    ld ave = 0, n = n1+n2+n3;
    if (n1 > 0)
        ave += n1*recurse(n1-1, n2, n3);
    if (n2 > 0)
        ave += n2*recurse(n1+1, n2-1, n3);
    if (n3 > 0)
        ave += n3*recurse(n1, n2+1, n3-1);
    return dp[n1][n2][n3] = ((ld)N + ave)/n;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                dp[i][j][k] = -1;

    cin >> N;
    for (int i = 1, a; i <= N; i++)
        cin >> a, cnt[a]++;
    cout << setprecision(10) << recurse(cnt[1], cnt[2], cnt[3]) << '\n';

    return 0;
}
