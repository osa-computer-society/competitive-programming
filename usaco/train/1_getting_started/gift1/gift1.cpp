/*
ID: a.cai6
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string,int> money;

int main()
{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    int N;
    fin >> N;
    
    string names[N];
    
    for (int i = 0; i < N; i++) {
        fin >> names[i];
        money[names[i]] = 0;
    }
    
    string giver, receiver;
    int amt, g;
    for (int i = 0; i < N; i++)
    {
        fin >> giver;
        fin >> amt >> g;
        if (g > 0)
        {
            int each = amt / g;
            int remain = amt % g;
            money[giver] -= amt;
            money[giver] += remain;
            for (int j = 0; j < g; j++)
            {
                fin >> receiver;
                money[receiver] += each;
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        fout << names[i] << " " << money[names[i]] << endl;
        
    return 0;
}