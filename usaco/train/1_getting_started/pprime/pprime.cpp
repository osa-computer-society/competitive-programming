// solved 2020-06-31
// took a while - originally I used Eratosthene's Sieve to track primes,
// but the memory storage was too large

#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
using namespace std;

int a, b;

bool is_prime(int n)
{
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int p = 5; p*p <= n; p += 6)
        if (n % p == 0 || n % (p+2) == 0) return false;
    return true;
}

void recurse(int max_digs, int num_digs, int *d, ofstream *fout)
{
    if (num_digs == max_digs)
    {
        int x = 0;
        for (int i = 1; i <= num_digs / 2; i++)
            x += (pow(10, num_digs-i) + pow(10, i-1)) * d[i];
        if (num_digs & 1) // odd
            x += pow(10, num_digs / 2) * d[num_digs / 2 + 1];
        if (x >= a && x <= b && is_prime(x)) *fout << x << '\n';
        return;
    }

    if (num_digs & 1) // odd
        recurse(max_digs, num_digs + 1, d, fout);
    else
        for (int i = num_digs >= 2 ? 0 : 1; i <= 9; i++)
        {
            d[num_digs/2+1] = i;
            recurse(max_digs, num_digs + 1, d, fout);
        }
}

int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    fin >> a >> b;

    int d[10];
    for (int max_digits = 1; max_digits <= log10(b) + 1; max_digits++)
        recurse(max_digits, 0, d, &fout);
    
    fin.close();
    fout.close();
    return 0;
}
