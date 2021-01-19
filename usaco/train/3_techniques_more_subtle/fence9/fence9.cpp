/*
ID: a.cai61
TASK: fence9
LANG: C++14
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("fence9.in");
ofstream fout("fence9.out");

int gcd(int a, int b)
{
    if (a < b)
        a = a + b, b = a - b, a = a - b;
    int r;
    while ((r = a % b))
        a = b, b = r;
    return b;
}

int main()
{
    int x, y, p;
    fin >> x >> y >> p;

    if (y == 0)
    {
        fout << 0 << '\n';
        fin.close();
        fout.close();
        return 0;
    }

    // pick's: a = i + b/2 - 1
    // therefore i = 2*a - b + 2
    int b = p;
    // first line
    if (x == 0)
        b += y;
    else
        b += gcd(x, y);
    // second line
    if (x == p)
        b += y;
    else
        b += gcd(abs(p - x), y);

    fout << (y * p - b + 2) / 2 << '\n';

    fin.close();
    fout.close();
    return 0;
}
