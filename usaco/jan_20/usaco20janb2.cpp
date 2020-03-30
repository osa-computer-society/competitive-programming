// Problem ID: 
// By 

#include <iostream>
#include <cstring>
#define MAXN 1005
using namespace std;

int b[MAXN], a[MAXN];
bool taken[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++)
        cin >> b[i];

    for (int i = 1; i <= N; i++)
    {
        memset(a, 0, sizeof(a));
        memset(taken, 0, sizeof(taken));
        a[1] = i;
        taken[i] = true;
        bool works = true;
        for (int j = 2; j <= N; j++)
        {
            a[j] = b[j] - a[j-1];
            if (a[j] < 1 || a[j] > N || taken[a[j]])
            {
                works = false;
                break;
            }
            taken[a[j]] = true;
        }
        if (!works) continue;
        for (int i = 1; i <= N; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}
