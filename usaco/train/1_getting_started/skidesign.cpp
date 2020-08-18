/*
ID: a.cai61
TASK: skidesign
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    
    int n;
    fin >> n;

    int heights[n];
    for (int i = 0; i < n; i++)
        fin >> heights[i];
    sort(heights, heights + n);

    int ans = 0x3f3f3f3f, cost, x;
    for (int low = 0; low <= 100-17; low++)
    {
        cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] < low)
                x = low - heights[i];
            else if (heights[i] > low+17)
                x = heights[i] - (low+17);
            else
                x = 0;
            cost += x * x;
        }
        ans = min(cost, ans);
    }

    fout << ans << '\n';

    fin.close();
    fout.close();
    return 0;
}
