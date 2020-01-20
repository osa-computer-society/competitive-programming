// Problem ID: 
// By 

#include <iostream>
#define MAXN 3005
#define MAXM 105
using namespace std;

int N, M, A[MAXN], B[MAXM], dp[MAXN][MAXM];

int solve(int i, int j)
{
    if (i > N || j > M) return -1;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = A[i] + solve(i+2, j);
    ans = max(ans, solve(i+2, j));
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> B[i];
    
    cout << solve(0, 0) << '\n';

    return 0;
}
