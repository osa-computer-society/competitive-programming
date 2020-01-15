#include <iostream>
using namespace std;

int main()
{   
    int N;
    cin >> N;
    int lg = -1, val = -1, A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] == 0)
            val = lg;
        else if (A[i] < lg)
        {
            cout << "NO\n";
            return 0;
        }
        lg = max(A[i], lg);
    }
    for (int i = 1; i < N; i++)
    {
        int a = A[i] ? A[i] : val;
        int b = A[i-1] ? A[i-1] : val;
        if (a < b)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}