// solved 2020-07-24

#include <iostream>
#include <fstream>
#define MAXN 12
using namespace std;

bool allowed[MAXN];

bool all_good_digits(int n)
{
    while (n > 0)
    {
        if (!allowed[n%10]) return false;
        n /= 10;
    }
    return true;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int n;
    fin >> n;
    int t;
    for (int i = 0; i < n; i++)
        fin >> t, allowed[t] = true;
    
    int total = 0;
    int a, b, c, d, e, x, y, f, g;
    bool good = true;
    for (a = 1; a < 10; a++)
    if (allowed[a])
    for (b = 0; b < 10; b++)
    if (allowed[b])
    for (c = 0; c < 10; c++)
    if (allowed[c])
    for (d = 1; d < 10; d++)
    if (allowed[d])
    for (e = 0; e < 10; e++)
    if (allowed[e])
    {
        x = 100*a + 10*b + c;
        y = 10*d + e;

        // Check that f is 3 digits, all digits are allowed
        f = e*x;
        g = d*x;
        if (f < 100 || f >= 1000 || !all_good_digits(f)) continue;
        if (g < 100 || g >= 1000 || !all_good_digits(g)) continue;

        int n = x*y;
        if (n >= 10000 || !all_good_digits(n)) continue;
        total++;
    }

    fout << total << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
