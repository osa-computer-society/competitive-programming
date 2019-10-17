// Problem ID: 10041
// By Alexander Cai
// Accepted

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int cases, r, n;
    vector<int> houseNumbers;
    cin >> cases;

    while (cases--)
    {
        cin >> r;
        houseNumbers.clear();
        
        for (int i = 0; i < r; i++)
        {
            cin >> n;
            houseNumbers.push_back(n);
        }

        sort(houseNumbers.begin(), houseNumbers.end());
        int median = houseNumbers[r / 2];
        int total = 0;
        for (int i = 0; i < r; i++)
            total += abs(houseNumbers[i] - median);

        cout << total << endl;
    }
    
    return 0;
}
