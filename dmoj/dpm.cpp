// Problem ID: Candies
// By Alexander Cai
// Keywords: 2D, Dynamic Programming, Prefix Sum Array

#include <iostream>
#include <string.h>
#define MAXN 105
#define MAXK 100005
using namespace std;
typedef long long ll;

int a[MAXN], N, K;
ll dp[MAXN][MAXK], psa[MAXN][MAXK];

const ll MOD = 1e9 + 7;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

	int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];

	dp[0][0] = 1;
    for (int i = 0; i <= K; i++)
        psa[0][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = 1, psa[i][0] = 1;
        for (int j = 1; j <= K; j++)
        {
            dp[i][j] = psa[i-1][j];
            if (j-a[i]-1 >= 0) dp[i][j] -= psa[i-1][j-a[i]-1];
            dp[i][j] %= MOD;
            psa[i][j] = psa[i][j-1] + dp[i][j];
		}
	}
 
	cout << dp[N][K] << '\n';
 
	return 0;
}
