// solved

// math, arithmetic

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#define MAXD 100005
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

int pos[MAXD];

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int main()
{
    int N, D;
    fin >> N >> D;

    stringstream ss;

    ss << N / D << '.';

    memset(pos, -1, sizeof(pos));

    int i = ss.str().size();
    int rem = N % D, q;
    if (rem == 0)
        fout << ss.str() << "0\n";
    else
    {
        pos[rem] = i++;
        while (true)
        {
            q = rem * 10 / D;
            rem = rem * 10 % D;
            ss << q;
            if (rem == 0)
                break;
            if (pos[rem] != -1)
                break;
            else
                pos[rem] = i++;
        }

        string s = ss.str();

        if (rem != 0)
        {
            s.insert(s.begin() + pos[rem], '(');
            s += ')';
        }

        if (s.size() > 76)
        {
            for (int i = 0; i < s.size(); i += 76)
            {
                fout << s.substr(i, min((size_t) 76, s.size() - i)) << '\n';
            }
        }
        else
            fout << s << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
