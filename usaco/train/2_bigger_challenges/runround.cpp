/*
ID: a.cai61
TASK: runround
LANG: C++14
*/

// Solved 2020-08-18

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
typedef long long ll;

int num[10];
bool seen[10];

bool is_round(ll n)
{
    int i;
    memset(seen, 0, sizeof(seen));
    for (i = 0; n > 0; i++, n /= 10)
        num[i] = n % 10;

    int j = i-1;
    for (int c = 0; c < i; c++)
    {
        if (seen[num[j]] || num[j] == 0) return false;
        seen[num[j]] = true;
        j = (j+(i-1)*num[j])%i;
    }
    return j == i-1;
}

int main()
{
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    ll n;
    fin >> n;
    n++;
    while (!is_round(n)) n++;
    fout << n << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
