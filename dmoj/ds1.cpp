// Problem ID: ds1
// By Alexander Cai
// Keywords: Binary Indexed Tree, Fenwick Tree, Data Structures

#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long ll;

ll N, M, x[MAXN], bit[MAXN], freq[MAXN];

void update(ll bit[], int i, int val)
{
    while (i <= MAXN)
    {
        bit[i] += val;
        i += (i&-i);
    }
}

ll query(ll bit[], int i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (i&-i);
    }
    return ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> x[i];
        update(bit, i, x[i]);
        update(freq, x[i], 1);
    }

    char c;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> c;
        if (c == 'C')
        {
            cin >> a >> b;
            update(bit, a, b-x[a]);
            update(freq, x[a], -1);
            update(freq, b, 1);
            x[a] = b;
        }
        else if (c == 'S')
        {
            cin >> a >> b;
            cout << query(bit, b) - query(bit, a-1) << '\n';
        }
        else if (c == 'Q')
        {
            cin >> a;
            cout << query(freq, a) << '\n';
        }
    }

    return 0;
}
