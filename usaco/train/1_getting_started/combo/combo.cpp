// Solved 2020-07-24

#include <iostream>
#include <fstream>
using namespace std;

int n, c1[5], c2[5];

bool close(int &a, int &b)
{
    return abs(a-b) <= 2 || abs(a-b-n) <= 2 || abs(a-b+n) <= 2;
}

int main()
{
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    fin >> n >> c1[0] >> c1[1] >> c1[2] >> c2[0] >> c2[1] >> c2[2];

    int total = 0;
    for (int a = 1; a <= n; a++)
    for (int b = 1; b <= n; b++)
    for (int c = 1; c <= n; c++)
        if ((close(a, c1[0]) && close(b, c1[1]) && close(c, c1[2]))
        || (close(a, c2[0]) && close(b, c2[1]) && close(c, c2[2])))
            total++;
    fout << total << '\n';
    fin.close();
    fout.close();
    return 0;
}
