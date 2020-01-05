// Problem ID: simplegame
// By Alexander Cai
// Solved 3 Jan 2020

#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    int A[N], lmax[N], rmax[N], l = 0, r = N-1;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        lmax[i] = l;
        if (A[i] > A[l]) l = i;
    }
    for (int i = N-1; i >= 0; i--)
    {
        rmax[i] = r;
        if (A[i] > A[r]) r = i;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << lmax[i] << ' ' << rmax[i] << '\n';
    // }

    int x;
    for (int i = 0; i < Q; i++)
    {
        cin >> x;
        cout << lmax[x-1] + 1 << ' ' << rmax[x-1] + 1 << '\n';
    }

    return 0;
}
