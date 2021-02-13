#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAXCOWS = 1e5 + 5;
const int MAXMOOVES = 2e5 + 5;

pii mooves[MAXMOOVES];
int cowat[MAXCOWS];
int poscount[MAXCOWS];
bool adj[MAXCOWS][MAXCOWS];

int main()
{
    // basic input
    int ncows, nmooves;
    cin >> ncows >> nmooves;

    for (int i = 1; i <= nmooves; ++i)
    {
        cin >> mooves[i].first >> mooves[i].second;
    }

    for (int i = 1; i <= ncows; ++i)
        cowat[i] = i;

    for (int j = 1; j <= nmooves; ++j)
    {
        int a = mooves[j].first, b = mooves[j].second;

        if (!adj[cowat[a]][b])
        {
            adj[cowat[a]][b] = 1;
            poscount[cowat[a]]++;
        }
        if (!adj[cowat[b]][a])
        {
            adj[cowat[b]][a] = 1;
            poscount[cowat[b]]++;
        }

        int t = cowat[b];
        cowat[b] = cowat[a];
        cowat[a] = t;
    }

    for (int i = 1; i <= ncows; ++i)
    {
        if (cowat[i] == i)
        {
            cout << poscount[i] << '\n';
        }
    }

    return 0;
}