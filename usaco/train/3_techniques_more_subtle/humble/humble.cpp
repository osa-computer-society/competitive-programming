/*
ID: a.cai61
TASK: humble
LANG: C++14
*/

// solved 2020-09-16

#include <iostream>
#include <fstream>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
#define MAXK 105
#define MAXN 100005
using namespace std;
typedef long long ll;

ifstream fin("humble.in");
ofstream fout("humble.out");

int prime[MAXK]; // the list of input primes
ll coeff[MAXK]; // coeff[i] is the number n such that at the end of each loop, prime[i] * hum[coeff[i]] > the largest humble number
ll hum[MAXN]; // hum[i] is the ith humble number

int main()
{
    int K, N;
    fin >> K >> N;
    FOR(i, K) fin >> prime[i];

    hum[0] = 1;
    ll lo;
    int ploi;
    FOR(i, N)
    {
        lo = 0x3f3f3f3f3f3f3f3f;
        ploi = -1;
        FOR(j, K)
        {
            while (prime[j] * hum[coeff[j]] <= hum[i-1])
                coeff[j]++;
            if (prime[j] * hum[coeff[j]] < lo)
                lo = prime[j] * hum[coeff[j]], ploi = j;
        }
        hum[i] = lo;
        coeff[ploi]++;
    }
    
    fout << hum[N] << '\n';

    fin.close();
    fout.close();
    return 0;
}
