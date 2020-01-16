/*
ID: a.cai61
TASK: ride
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string s, t;
    fin >> s >> t;
    int a = 1, b = 1;

    if (s.size() == 0) a = 0;
    else
        for (char c : s)
            a = (a * (c-'A'+1)) % 47;
    if (t.size() == 0) b = 0;
    else for (char c : t) b = (b * (c-'A'+1)) % 47;

    if (a == b) fout << "GO\n";
    else fout << "STAY\n";
    
    return 0;
}
