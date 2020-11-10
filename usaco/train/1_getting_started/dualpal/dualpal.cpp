// solved 2020-07-22

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool is_pal(string s)
{
    int n = s.size();
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-1-i]) return false;
    return true;
}

string num_to_base(int num, int base)
{
    string temp = "";
    while (num > 0)
    {
        int c = num % base;
        if (c > 9) temp.push_back(c-10 + 'A');
        else temp.push_back(c + '0');
        num /= base;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int n, s;
    fin >> n >> s;
    
    int c = 0;
    bool pal;
    for (int i = s+1; c < n; i++)
    {
        pal = false;
        for (int k = 2; k <= 10; k++)
        {
            if (is_pal(num_to_base(i, k)))
            {
                if (!pal) pal = true;
                else { fout << i << '\n'; c++; break; }
            }
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}
