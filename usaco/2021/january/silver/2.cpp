#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

string s;
vector<pii> strokes[30];

int main()
{
    int N, Q;
    cin >> N >> Q;
    cin >> s;

    for (int i = 0; i < 26; ++i)
    {
        int start = -1, last_index = s.size();
        for (int j = 0; j < N; ++j)
        {
            if (s[j] < 'A' + i)
            {
                if (start != -1)
                {
                    strokes[i].push_back({start, j});
                }
                start = -1;
            }
            else
            {
                if (s[j] == 'A' + i)
                    last_index = j;
                if (start == -1)
                {
                    start = j;
                }
            }
        }

        if (start != -1)
            strokes[i].push_back({start, last_index + 1});

        // for (pii p : strokes[i])
        // {
        //     cout << i << ": " << p.first << " " << p.second << "\n";
        // }
    }

    for (int i = 1; i <= Q; ++i)
    {
        int a, b;
        cin >> a >> b;

        int total = 0;
        for (int j = 0; j < 26; ++j)
        {
            total += strokes[j].size();
            for (pii stroke : strokes[j])
            {
                if (a > stroke.first + 1 && b < stroke.second - 1)
                {
                    // cout << "added " << stroke.first << " " << stroke.second << "\n";
                    total++;
                }
                else if (a <= stroke.first + 1 && b >= stroke.second)
                {
                    // cout << "subtracted " << stroke.first << " " << stroke.second << "\n";
                    total--;
                }
            }
        }
        cout << total << '\n';
    }

    return 0;
}