// Problem ID: 
// By 

#include <iostream>
#include <string>
using namespace std;

int grid[5][5];
bool x[5][5];

bool complete()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (x[i][j])
                return 0;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> s;
            if (s == "X") x[i][j] = 1;
            else grid[i][j] = stoi(s);
        }
    }

    while (!complete())
    {
        bool changed = 0;
        for (int i = 0; i < 3; i++)
        {
            if (x[i][0] && !x[i][1] && !x[i][2])
                grid[i][0] = 2*grid[i][1] - grid[i][2], x[i][0] = 0, changed = true;
            if (x[i][1] && !x[i][0] && !x[i][2])
                grid[i][1] = (grid[i][0] + grid[i][2])/2, x[i][1] = 0, changed = true;
            if (x[i][2] && !x[i][0] && !x[i][1])
                grid[i][2] = 2*grid[i][1] - grid[i][0], x[i][2] = 0, changed = true;
            
            if (x[0][i] && !x[1][i] && !x[2][i])
                grid[0][i] = 2*grid[1][i] - grid[2][i], x[0][i] = 0, changed = true;
            if (x[1][i] && !x[0][i] && !x[2][i])
                grid[1][i] = (grid[0][i] + grid[2][i])/2, x[1][i] = 0, changed = true;
            if (x[2][i] && !x[0][i] && !x[1][i])
                grid[2][i] = 2*grid[1][i] - grid[0][i], x[2][i] = 0, changed = true;
        }
        if (changed) continue;
        if (x[1][1])
        {
            grid[1][1] = 0, x[1][1] = 0;
            continue;
        }
        for (int j = 0; j <= 2; j += 2)
        {
            if (!x[j][j])
            {
                if (x[j][1]) grid[j][1] = 0, x[j][1] = 0, changed = 1;
                if (x[1][j]) grid[1][j] = 0, x[1][j] = 0, changed = 1;
                if (changed) break;
            }
        }
        if (changed) continue;
    }

    for (int i = 0; i < 3; i++)
        cout << grid[i][0] << ' ' << grid[i][1] << ' ' << grid[i][2] << '\n';


    return 0;
}
