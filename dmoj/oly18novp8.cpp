// Problem ID: oly18novp8
// By Alexander Cai
// Keywords: Binary Indexed Tree, Fenwick Tree, Data Structures

#include <iostream>
#define MAXN 15005
#define MAXX 32005
using namespace std;

int N, freq[MAXX], lvl[MAXN];

void update(int i)
{
    for (; i <= MAXX; i+=(i&-i))
        freq[i]++;
}

int query(int i)
{
    int ans = 0;
    for (; i > 0; i-=(i&-i))
        ans += freq[i];
    return ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1, x, y; i <= N; i++)
    {
        cin >> x >> y;
        lvl[query(x+1)]++;
        update(x+1);
    }

    for (int i = 0; i < N; i++) cout << lvl[i] << '\n';

    return 0;
}
