// Problem ID: oly19practice74
// By 
// Unfinished

#include <iostream>
#include <algorithm>
#include <utility>
#define MAXN 20005
using namespace std;
typedef pair<int,int> pii;
vector<pii> wall[MAXN];
int a(int n) { return n + 10000; }

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int x1, y1, x2, y2, l = MAXN, r = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int c = x1; c < x2; c++)
            wall[a(c)][a(y2)]++, wall[a(c)][a(y1)]--;
        l = min(l, x1);
        r = max(r, x2);
    }

    int stack = 0, k = 0, total = 0;
    for (int col = l; col <= min(r, MAXN); col++)
    {
        for (pii p : wall[col])
        {
            if (wall[a(col)][a(p.first)] && stack == 0) k = r;
            stack += wall[a(col)][a(r)];
            if (wall[a(col)][a(r)] < 0 && stack == 0) total += r-k;
        }
    }

    cout << total << endl;

    return 0;
}
