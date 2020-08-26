/*
ID: a.cai61
TASK: prefix
LANG: C++14
*/

// solved 2020-08-26

#include <iostream>
#include <fstream>
#include <string>
#define MAXP 205
#define MAXLEN 200005
using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

string prim[MAXP];
string s;
bool valid[MAXLEN]; // valid[k] is whether or not the first k characters of s can be created

int main()
{
    string t;
    int cnt = 0;
    while (fin >> t, t != ".")
        prim[cnt++] = t;
    while (fin >> t)
        s += t;
    
    valid[0] = true;
    for (int i = 0; i < s.size(); ++i)
        if (valid[i])
            for (int j = 0; j < cnt; ++j) // for each primitive, if it matches the next part, we set that to true
                if (i + prim[j].size() <= s.size() && s.substr(i, prim[j].size()) == prim[j])
                    valid[i+prim[j].size()] = true;
    
    for (int i = s.size(); i >= 0; i--)
    {
        if (valid[i])
        {
            fout << i << '\n';
            break;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
