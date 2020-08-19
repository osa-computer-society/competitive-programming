/*
ID: a.cai61
TASK: subset
LANG: C++14
*/

// Solved 2020-08-18

#include <iostream>
#include <fstream>
#define MAXSUM 39*10
using namespace std;
typedef long long ll;

ll dp[MAXSUM+5];

int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    int N;
    fin >> N;

    if (N*(N+1) % 4 != 0)
    {
        fout << "0\n";
        fin.close();
        fout.close();
        return 0;
    }

    int s = N*(N+1)/4;
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int k = s; k >= i; k--)
            dp[k] += dp[k-i];
    
    fout << dp[s] / 2 << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
