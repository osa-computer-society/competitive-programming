#include <iostream>
#include <algorithm>
#include <fstream>
#define MAXFARMERS 5005
using namespace std;
typedef pair<int,int> pii;

// cost, amount
pii farmers[MAXFARMERS];

int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        fin >> farmers[i].first >> farmers[i].second;
    }

    sort(farmers, farmers + m);

    int c = 0, total = 0;
    while (true)
    {
        // n: amount remaining
        if (n <= farmers[c].second)
        {
            total += farmers[c].first * n;
            break;
        }
        else
        {
            total += farmers[c].first * farmers[c].second;
            n -= farmers[c].second;
            c++;
        }
    }

    fout << total << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
