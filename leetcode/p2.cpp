#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

long long smallestNumber(long long num)
{
    int counts[10];
    for (int i = 0; i < 10; ++i)
        counts[i] = 0;
    bool neg = num < 0;
    if (neg)
        num = -num;
    while (num > 0)
    {
        long long q = num / 10;
        int r = num % 10;
        counts[r]++;
        num /= 10;
    }

    long long ans = 0;

    if (neg)
    {
        for (int j = 9; j >= 0; --j)
        {
            for (int i = 0; i < counts[j]; ++i)
            {
                ans = ans * 10 + j;
            }
        }
    }
    else
    {
        if (counts[0] > 0)
        {
            for (int j = 1; j < 10; ++j)
            {
                if (counts[j] > 0)
                {
                    ans = j;
                    --counts[j];
                    break;
                }
            }
            for (int j = 0; j < counts[0]; ++j)
                ans *= 10;
        }

        for (int j = 1; j < 10; ++j)
        {
            for (int i = 0; i < counts[j]; ++i)
            {
                ans = ans * 10 + j;
            }
        }
    }

    return neg ? -ans : ans;
}

int main()
{
    long long k;
    cin >> k;
    cout << smallestNumber(k) << '\n';

    return 0;
}