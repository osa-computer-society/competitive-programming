/*
ID: a.cai61
TASK: beads
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int N;
    fin >> N;
    string s;
    fin >> s;

    int lg = -1;

    for (int i = 0; i < N; i++) // we check for a break between i and i-1
    {
        int p = (i-1+N)%N;
        char c1 = s[i], c2 = s[p];
        int m = 0;
        int k = i;

        cout << p << '|' << i << '\n';
        while (k != p)
        {
            if (c1 == 'w')
            {
                m++, k = (k+1)%N;
                if (s[k] != 'w')
                    c1 = s[k];
            }
            else if (s[k] == 'w' || s[k] == c1)
                m++, k = (k+1)%N;
            else
                break;
        }

        cout << "k: " << k << '\n';

        if (k == p)
        {
            lg = N;
            break;
        }

        int j = p;
        while (j != (k-1+N)%N)
        {
            if (c2 == 'w')
            {
                m++, j = (j-1+N)%N;
                if (s[j] != 'w')
                    c2 = s[j];
            }
            else if (s[j] == 'w' || s[j] == c2)
                m++, j = (j-1+N)%N;
            else
                break;
        }

        cout << "j: " << j << '\n';
        cout << "m: " << m << '\n';
        lg = max(lg, m);
    }

    fout << lg << '\n';
    cout << lg << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
