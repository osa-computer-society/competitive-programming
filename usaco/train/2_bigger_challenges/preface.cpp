/*
ID: a.cai61
TASK: preface
LANG: C++14
*/

// Solved 2020-08-18

#include <iostream>
#include <fstream>
using namespace std;

char chars[] = "IVXLCDM";
int vals[10];

int main()
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");

    int N;
    fin >> N;

    for (int i = 1; i <= N; i++)
    {
        int k = i;
        int len = 0; // place value
        while (k > 0)
        {
            int d = k % 10;

            switch (d)
            {
            case 1: case 2: case 3:
                vals[len*2] += d;
                break;
            case 8:
                vals[len*2]++;
            case 7:
                vals[len*2]++;
            case 6: case 4:
                vals[len*2]++;
            case 5:
                vals[len*2+1]++;
                break;
            case 9:
                vals[len*2+2]++;
                vals[len*2]++;
                break;
            default:
                break;
            }

            len++;
            k /= 10;
        }
    }

    for (int i = 0; i < 10; i++)
        if (vals[i])
            fout << chars[i] << ' ' << vals[i] << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
