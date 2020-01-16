/*
ID: a.cai61
TASK: NAME_OF_TASK
LANG: C++14
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("NAME_OF_TASK.in");
    ofstream fout("NAME_OF_TASK.out");

    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    
    fin.close();
    fout.close();
    return 0;
}
