// Problem ID: 
// By 

#include <iostream>
#include <cstring>
#define MAXN 3005
#define MAXM 105
using namespace std;
typedef long long ll;

int N, M, A[MAXN], B[MAXM];
ll dp[MAXN][MAXM];

ll solve(int i, int j)
{
    if (i > N || j > M) return -0x3f3f3f3f;
    if (i == N && j == M) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll ans = -0x3f3f3f3f;
    ans = max(ans, A[i] + solve(i+2, j));
    ans = max(ans, A[i] + solve(i+1, j+1));
    ans = max(ans, B[j] + solve(i+1, j+1));
    ans = max(ans, B[j] + solve(i, j+2));
    ans = max(ans, solve(i+1, j));
    ans = max(ans, solve(i, j+1));

    return dp[i][j] = ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> B[i];
    
    cout << solve(0, 0) << '\n';

    return 0;
}
