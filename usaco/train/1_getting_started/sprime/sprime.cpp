/*
ID: a.cai61
TASK: sprime
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <cstring>
#define MAXP 400000
using namespace std;

int prime[MAXP];

bool is_prime(int n)
{
    if (n < MAXP && prime[n] != -1) return prime[n];
    if (n <= 3) return prime[n] = n > 1;
    if (n % 2 == 0 || n % 3 == 0) return n < MAXP ? (prime[n] = false) : false;
    for (int p = 5; p*p <= n; p += 6)
        if (n % p == 0 || n % (p+2) == 0) return n < MAXP ? (prime[n] = false) : false;
    return n < MAXP ? (prime[n] = true) : true;
}

void recurse(int n, int nd, int x, ofstream *fout)
{
    if (nd == n)
    {
        *fout << x << '\n';
        return;
    }
    
    x *= 10;
    if (is_prime(x+1))
        recurse(n, nd+1, x+1, fout);
    if (is_prime(x+3))
        recurse(n, nd+1, x+3, fout);
    if (is_prime(x+7))
        recurse(n, nd+1, x+7, fout);
    if (is_prime(x+9))
        recurse(n, nd+1, x+9, fout);
}

int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    memset(prime, -1, sizeof(prime));

    int n;
    fin >> n;
    recurse(n, 1, 2, &fout);
    recurse(n, 1, 3, &fout);
    recurse(n, 1, 5, &fout);
    recurse(n, 1, 7, &fout);

    fin.close();
    fout.close();
    return 0;
}
