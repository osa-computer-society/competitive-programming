// Solved 2020-07-22

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
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
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int base;
    fin >> base;

    string s;
    for (int i = 1; i <= 300; i++)
    {
        s = num_to_base(i*i, base);
        if (is_pal(s))
            fout << num_to_base(i, base) << ' ' << s << '\n';
    }
    
    fin.close();
    fout.close();
    return 0;
}
