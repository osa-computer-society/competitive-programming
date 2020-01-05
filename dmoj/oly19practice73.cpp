// Problem ID: oly19practice73
// By Alexander Cai

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, B;
    cin >> N >> B;

    priority_queue<int, vector<int>, greater<int>> stacks[N];

    for (int i = 0, p, s; i < N; i++)
    {
        cin >> p >> s;
        for (int j = 0; j < N; j++)
            if (j == i) stacks[j].push((p>>1)+s);
            else stacks[j].push(p+s);
    }

    int greatest = 0, i = 0, ans = 0, total = 0, k;
    for (; ans = 0, total = 0, i < N; i++)
    {
        while (!stacks[i].empty())
        {
            k = stacks[i].top(); stacks[i].pop();
            if (total + k > B) break;
            total += k;
            ans++;
        }
        if (ans > greatest) greatest = ans;
    }

    cout << greatest << endl;

    return 0;
}
