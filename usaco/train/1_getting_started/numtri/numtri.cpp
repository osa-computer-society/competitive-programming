// solved 2020-06-31

#include <iostream>
#include <fstream>
using namespace std;

int x[1001], total[1001], r;

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    fin >> r;
    for (int row = 1; row <= r; row++)
    {
        for (int i = 1; i <= row; i++)
            fin >> x[i];
        for (int i = row; i >= 1; i--)
            total[i] = max(total[i], total[i-1]) + x[i];
    }
    
    int ans = -1;
    for (int i = 1; i <= r; i++)
        ans = max(ans, total[i]);
    fout << ans << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
