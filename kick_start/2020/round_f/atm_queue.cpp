// solved

#include <iostream>
#include <utility>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef pair<int,int> pii;

int main()
{
    int T;
    cin >> T;

    int N, A, X;
    pii queue[MAXN];
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> X;
        for (int i = 1; i <= N; ++i)
        {
            cin >> A;
            queue[i] = make_pair((A-1) / X, i);
        }
        
        sort(queue + 1, queue + N + 1);
        cout << "Case #" << t << ":";
        for (int i = 1; i <= N; ++i)
            cout << ' ' << queue[i].second;
        cout << '\n';
    }
    
    return 0;
}