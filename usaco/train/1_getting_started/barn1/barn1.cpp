// solved 2020-07-23

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXS 205
using namespace std;

int stalls[MAXS], diff[MAXS];

int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int m, s, c;
    fin >> m >> s >> c;

    // Get sorted list of occupied stalls
    for (int i = 0; i < c; ++i)
        fin >> stalls[i];
    sort(stalls, stalls + c);

    // get sorted list
    for (int i = 0; i < c-1; ++i)
        diff[i] = stalls[i+1] - stalls[i] - 1;
    sort(diff, diff + c - 1);

    int mm = c; // # of boards
    int ans = c; // # of covered stalls
    int i = 0;
    while (diff[i] == 0) // merge all adjacent cells
        ++i, --mm;
    while (mm > m)
        ans += diff[i], ++i, --mm;

    fout << ans << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
