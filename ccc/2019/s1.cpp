// Problem ID: 
// By 

#include <iostream>
#include <string>
using namespace std;
int grid[2][2];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[1][0] = 3;
    grid[1][1] = 4;
    
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c == 'H') swap(grid[0], grid[1]);
        else if (c == 'V') swap(grid[0][0], grid[0][1]), swap(grid[1][0], grid[1][1]);
    }

    cout << grid[0][0] << ' ' << grid[0][1] << '\n' << grid[1][0] << ' ' << grid[1][1] << '\n';

    return 0;
}
