// Problem ID:
// By Alexander Cai

#include <iostream>
#include <vector>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int maxn = 2005;
int A[maxn];

// vector<int> factors[17] = {
//     {1},
//     {1,2},
//     {1, 3},
//     {1,2,4},
//     {1,5},
//     {1,2,3,6},
//     {1,7},
//     {1,2,4,8},
//     {1,3,9},
//     {}
// };

int gcd(int a, int b)
{
    if (b > a)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (b > 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int x[maxn], y[maxn], z[maxn];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    FOR(i, 1, N)
    A[i] = 1;

    FOR(i, 1, M)
    {
        cin >> x[i] >> y[i] >> z[i];
        FOR(j, x[i], y[i])
        {
            if (A[j] % z[i] != 0)
            {
                // cout << A[j] << " , " << z << " , " << gcd(A[j], z) << "\n";
                A[j] *= z[i] / gcd(A[j], z[i]);
            }
        }
    }

    FOR(i, 1, M)
    {
        FOR(j, x[i], y[i])
        {
            
        }
    }

    return 0;
}
