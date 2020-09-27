// solved

// we simply use a greedy approach, since switching out a house with a cheaper one
// can only increase or maintain the # of houses we can buy

#include <iostream>
#include <algorithm>
using namespace std;

int A[100005];

int main()
{
    int T;
    cin >> T;
    int N, B, total, i;
    for (int k = 1; k <= T; k++)
    {
        cin >> N >> B;
        for (int i = 0; i < N; i++)
            cin >> A[i];
        sort(A, A + N);
        for (total = i = 0; i < N && total + A[i] <= B; i++)
            total += A[i];
        cout << "Case #" << k << ": " << i << '\n';
    }
    return 0;
}
