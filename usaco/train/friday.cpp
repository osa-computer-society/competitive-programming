/*
ID: a.cai61
TASK: friday
LANG: C++14
*/

#include <iostream>
#include <fstream>
using namespace std;

int cnt[7];

int num_days(int year, int m)
{
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
}

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    
    int N;
    fin >> N;

    int day = 0; // 13 January 1900 was Saturday

    for (int y = 1900; y < 1900 + N; y++)
    {
        for (int m = 1; m <= 12; m++)
        {
            cnt[day]++;
            day = (day + num_days(y, m)) % 7;
        }
    }

    for (int i = 0; i < 6; i++)
        fout << cnt[i] << ' ';
    fout << cnt[6] << '\n';

    fin.close();
    fout.close();
    return 0;
}
