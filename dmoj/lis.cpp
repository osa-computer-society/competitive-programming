// Problem ID: lis
// By Alexander Cai
// Keywords: Dynamic Programming, Longest Increasing Sequence

#include <iostream>
using namespace std;

int lis[1000005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, a, len = 1;
    cin >> N;
    cin >> lis[0];
    for (int i = 1; i < N; i++)
    {
        cin >> a;
        int *x = lower_bound(lis, lis+len, a);
        if (x == lis+len)
            lis[len++] = a;
        else
            *x = a;
    }
    cout << len << '\n';

    return 0;
}
