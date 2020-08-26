/*
ID: a.cai61
TASK: nocows
LANG: C++14
*/

// solved 2020-08-26

// simple DP
// careful for MOD restrictions and negative answers
// we use a prefix sum array for fast updates and queries

#include <iostream>
#include <fstream>
#define MAXN 205
#define MAXK 105
#define MOD 9901
using namespace std;

int sumtrees[MAXN][MAXK]; // sumtrees[n][k] := # trees with n nodes and a depth of k

ifstream fin("nocows.in");
ofstream fout("nocows.out");

int main()
{
    int N, K;
    fin >> N >> K;

    sumtrees[1][1] = 1;
    for (int n = 1; n <= N; ++n)
        for (int k = 1; k <= K; ++k)
        {
            for (int l = 1; l <= (n-1)/2; ++l) // # nodes in left subtree
            {
                int r = n-1-l;
                int ll = sumtrees[l][k-1] - sumtrees[l][k-2];
                int rr = sumtrees[r][k-1] - sumtrees[r][k-2];
                // one subtree needs depth k-1
                sumtrees[n][k] += (l == r ? 1 : 2) * (
                    ll * sumtrees[r][k-2] % MOD     // left
                    + sumtrees[l][k-2] * rr % MOD   // right
                    + ll * rr % MOD                 // both
                ) % MOD;
            }
            sumtrees[n][k] = (sumtrees[n][k] + sumtrees[n][k-1]) % MOD;
        }

    // don't forget the final mod
    fout << (sumtrees[N][K] - sumtrees[N][K-1] + MOD) % MOD << '\n';

    fin.close();
    fout.close();
    return 0;
}
