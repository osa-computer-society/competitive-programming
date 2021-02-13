// Problem ID: 
// By 

#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int pA = 0, pB = 0, pC = 0, A=0, B=0, C=0;
    for (int i = 0, a, b, c; i < N; i++)
    {
        cin >> a >> b >> c;
        A = a+max(pB, pC);
        B = b+max(pA, pC);
        C = c+max(pA, pB);
        pA = A; pB = B; pC = C;
    }

    cout << max(max(A, B), C) << '\n';

    return 0;
}
