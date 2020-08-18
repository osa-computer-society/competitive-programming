/*
ID: a.cai61
TASK: wormhole
LANG: C++14
*/

// solved 2020-07-24

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#define MAXN 14
using namespace std;
typedef pair<int,int> pii;

pii wormholes[MAXN];
int next_hole[MAXN], partner[MAXN]; // partner - paris of portals

int cycle_exists(int n)
{
    for (int start = 1; start <= n; start++)
    {
        int k = start;
        for (int i = 0; i < n; i++)
            k = next_hole[partner[k]];
        if (k != 0) return 1;
    }
    return 0;
}

int backtrack(int n)
{
    int i;
    // find first unpaired n
    for (i = 1; i <= n; i++)
        if (partner[i] == 0) break;

    if (i > n) return cycle_exists(n);
    
    int total = 0;
    for (int j = i+1; j <= n; j++)
    {
        if (partner[j] == 0)
        {
            partner[i] = j;
            partner[j] = i;
            total += backtrack(n);
            partner[i] = partner[j] = 0; // reset for backtracking
        }
    }
    return total;
}

int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    int n;
    fin >> n;

    for (int i = 1; i <= n; i++)
        fin >> wormholes[i].first >> wormholes[i].second;
    sort(wormholes+1, wormholes+1+n, [](const pii &l, const pii &r)
    {
        if (l.second == r.second) return l.first < r.first;
        return l.second < r.second;
    });
    for (int i = 2; i <= n; i++)
        if (wormholes[i].second == wormholes[i-1].second) // same y
            next_hole[i-1] = i;

    fout << backtrack(n) << '\n';

    fin.close();
    fout.close();
    return 0;
}
