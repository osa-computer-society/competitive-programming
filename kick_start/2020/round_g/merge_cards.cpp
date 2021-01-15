// Merge Cards

#include <iostream>
#include <iomanip>
#include <vector>
#define MAXN 10
using namespace std;
typedef long double ld;
typedef long long ll;

vector<ll> cards;
ll N;
ld total;
ll ncases;

void dfs(ll tot)
{
    if (cards.size() == 2)
    {
        total += tot + cards[0] + cards[1];
        ++ncases;
        return;
    }

    for (int i = 0; i < cards.size() - 1; ++i)
    {
        ll a = cards[i], b = cards[i + 1];
        cards.erase(cards.begin() + i, cards.begin() + i + 2);
        cards.insert(cards.begin() + i, a + b);
        dfs(tot+a+b);
        cards.erase(cards.begin() + i);
        cards.insert(cards.begin() + i, b);
        cards.insert(cards.begin() + i, a);
    }
}

int main()
{
    int T;
    cin >> T;
    cout << fixed << setprecision(9);

    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        cards.resize(N);
        total = ncases = 0;

        for (int i = 0; i < N; ++i)
            cin >> cards[i];

        dfs(0);

        cout << "Case #" << t << ": " << ((ld)total / ncases) << '\n';
    }

    return 0;
}
