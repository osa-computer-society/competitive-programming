// Problem ID: 
// By 

#include <iostream>
#include <string>
using namespace std;

int A[1005], B[1005];
long long dp[1005][1005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string S, T;
    cin >> S;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> T;
    for (int i = 0; i < N; i++)
        cin >> B[i];
    
    for (int i = 0; i <= N; i++)
        dp[0][i] = 0, dp[i][0] = 0;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if ((S[i-1] == 'W' && T[j-1] == 'L' && A[i-1] > B[j-1]) || (S[i-1] == 'L' && T[j-1] == 'W' && B[j-1] > A[i-1]))
                dp[i][j] = dp[i-1][j-1] + A[i-1] + B[j-1];
            dp[i][j] = max(max(dp[i][j], dp[i-1][j]), dp[i][j-1]);
        }
    }
    
    cout << dp[N][N] << '\n';

    return 0;
}
