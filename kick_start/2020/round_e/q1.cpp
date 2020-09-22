// solved

#include <iostream>
using namespace std;

int A[200005];

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> A[i];
        
        int ans = -1, len = 1, diff = A[2] - A[1];
        for (int i = 2; i <= N; i++)
        {
            int d = A[i] - A[i-1];
            if (d != diff)
            {
                ans = max(ans, len);
                len = 2;
                diff = d;
            }
            else
                len++;
        }
        ans = max(ans, len);
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}