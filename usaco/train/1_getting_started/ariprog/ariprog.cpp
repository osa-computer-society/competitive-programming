/*
ID: a.cai61
TASK: ariprog
LANG: C++14
*/

// solved 2020-06-30

#include <iostream>
#include <fstream>
using namespace std;

bool bisquare[2*250*250+1];

int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int n, m;
    fin >> n >> m;

    for (int p = 0; p <= m; p++)
        for (int q = 0; q <= m; q++)
            bisquare[p*p+q*q] = true;
    
    bool works, found = false;
    for (int d = 1; d*(n-1) <= 2*m*m; d++)
    {
        for (int a = 0; a <= 2*m*m - (n-1)*d; a++)
        {
            works = true;
            for (int i = 0; i < n; i++)
                if (!bisquare[a+d*i]) { works = false; break; }
            if (works) fout << a << ' ' << d << '\n', found = true;
        }
    }

    if (!found) fout << "NONE\n";
    
    fin.close();
    fout.close();
    return 0;
}
