// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 300005
#define MAXL 18
using namespace std;

int st[MAXL+5][MAXN], val[MAXN], d[MAXN];

int lca(int u, int v)
{
    if (d[u] < d[v]) swap(u, v); // u is farther
    for (int i = MAXL; i >= 0; i--)
        if (st[i][u] != -1 && d[st[i][u]] >= d[v])
            u = st[i][u];
    if (u == v) return u;
    for (int i = MAXL; i >= 0; i--)
        if (st[i][u] != -1 && st[i][u] != st[i][v])
            u = st[i][u], v = st[i][v];
    return st[0][u];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(st, -1, sizeof(st));
    d[0] = 0;

    int N;
    cin >> N;

    char op;
    int v, w;
    for (int i = 1; i <= N; i++)
    {
        cin >> op >> v;
        v = val[v];
        if (op == 'a')
        {
            st[0][i] = v;
            val[i] = i;
            d[i] = d[v] + 1;
            for (int j = 1; j <= MAXL; j++)
                if (st[j-1][i] != -1)
                    st[j][i] = st[j-1][st[j-1][i]];
        }
        else if (op == 'b')
        {
            val[i] = st[0][v];
            cout << v << '\n';
        }
        else if (op == 'c')
        {
            cin >> w;
            val[i] = v;
            cout << d[lca(v, val[w])] << '\n';
        }
    }

    return 0;
}
