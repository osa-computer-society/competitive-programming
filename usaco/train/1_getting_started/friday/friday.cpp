#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int frequency[7];

// calculate the number of days in a month in a given year
int num_days(int year, int month)
{
    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    if ((month <= 7 && (month & 1)) || (month >= 8 && (~month & 1)))
        return 31;
    return 30;
}

int main()
{
    int N;
    fin >> N;

    // 0 is Saturday, 1 is Sunday, ..., 6 is Friday
    int day = 0; // 13 January 1900 was Saturday

    for (int year = 1900; year < 1900 + N; year++)
    {
        for (int month = 1; month <= 12; month++)
        {
            frequency[day]++;
            day = (day + num_days(year, month)) % 7;
        }
    }

    for (int i = 0; i < 6; i++)
        fout << frequency[i] << ' ';
    fout << frequency[6] << '\n';

    fin.close();
    fout.close();
    return 0;
}
