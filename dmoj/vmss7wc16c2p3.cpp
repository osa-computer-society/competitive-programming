// Problem ID: 
// By 

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ind[1000005], arr[1000005], lis[1000005];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(ind, -1, sizeof(ind));

    int N;
    cin >> N;
    for (int i = 1, n; i <= N; i++)
    {
        cin >> n;
        ind[n] = i;
    }

    cin >> N;
    int cnt = 0;
    for (int i = 0, n; i < N; i++)
    {
        cin >> n;
        if (ind[n] != -1)
            arr[cnt++] = ind[n];
    }
    if (!cnt)
    {
        cout << "0\n";
        return 0;
    }

    int len = 1;
    lis[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        int *x = lower_bound(lis, lis+len, arr[i]);
        if (x == lis+len)
            lis[len++] = arr[i];
        else
            *x = arr[i];
    }

    cout << len << '\n';

    return 0;
}
