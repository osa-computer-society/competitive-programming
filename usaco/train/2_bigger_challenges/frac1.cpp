/*
ID: a.cai61
TASK: frac1
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;

int n;

void recurse(ofstream *fout, int n1, int d1, int n2, int d2)
{
    if (d1 + d2 > n)
        return;
    recurse(fout, n1, d1, n1 + n2, d1 + d2);
    *fout << n1 + n2 << '/' << d1 + d2 << '\n';
    recurse(fout, n1 + n2, d1 + d2, n2, d2);
}

int main()
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    fin >> n;

    fout << "0/1\n";
    recurse(&fout, 0, 1, 1, 1);
    fout << "1/1\n";

    fin.close();
    fout.close();
    return 0;
}
