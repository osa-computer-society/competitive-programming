// solved 2020-07-22

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encode_name(string name)
{
    string a = "";
    for (int i = 0; i < name.size(); i++)
    {
        int curr = name[i] - 'A';
        if (curr > 'Q' - 'A') curr--;
        a.push_back(curr / 3 + '2');
    }
    return a;
}

int main()
{
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");
    ofstream fout("namenum.out");

    string name; // e.g. "4734"
    fin >> name;
    
    bool found = false;
    string s;
    while (dict >> s)
        if (encode_name(s).compare(name) == 0) // they are equal
            fout << s << '\n', found = true;
    
    if (!found) fout << "NONE\n";
    
    fin.close();
    fout.close();
    return 0;
}
