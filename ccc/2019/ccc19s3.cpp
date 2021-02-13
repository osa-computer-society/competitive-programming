

#include <iostream>
#include <utility>
#include <string>
using namespace std;
typedef pair<int, int> pii;

int a[4][4];
bool v[4][4];
int row[4], col[4];
int cnt = 0;
pii order[] = {
    {2, 2},
    {2, 1},
    {2, 3},
    {1, 2},
    {3, 2},
};

void fillCell(int, int);
void fillR(int);
void fillC(int);

int main()
{
    string s;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> s;
            if (s == "X")
            {
                v[i][j] = true;
                row[i]++;
                col[j]++;
                cnt++;
            }
            else
                a[i][j] = stoi(s);
        }
    }

    while (cnt > 0)
    {
        bool cont = false;
        for (int i = 1; i <= 3; i++)
            if (row[i] == 1)
                fillR(i), cont = true;
        if (cont)
            continue;
        for (int i = 1; i <= 3; i++)
            if (col[i] == 1)
                fillC(i), cont = true;
        if (cont)
            continue;
        for (pii e : order)
            if (v[e.first][e.second])
            {
                fillCell(e.first, e.second), cont = true;
                break;
            }
        if (cont)
            continue;

        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (v[i][j])
                    fillCell(i, j), i = 4, j = 4;
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

void fillCell(int r, int c)
{
    row[r]--;
    col[c]--;
    cnt--;
    v[r][c] = false;
    a[r][c] = 0;
}

void fillR(int r)
{
    if (v[r][1])
    {
        a[r][1] = 2 * a[r][2] - a[r][3];
        col[1]--;
        v[r][1] = false;
    }
    if (v[r][3])
    {
        a[r][3] = 2 * a[r][2] - a[r][1];
        col[3]--;
        v[r][3] = false;
    }
    if (v[r][2])
    {
        a[r][2] = (a[r][1] + a[r][3]) / 2;
        col[2]--;
        v[r][2] = false;
    }
    row[r]--;
    cnt--;
}

void fillC(int c)
{
    if (v[1][c])
    {
        a[1][c] = 2 * a[2][c] - a[3][c];
        row[1]--;
        v[1][c] = false;
    }
    if (v[3][c])
    {
        a[3][c] = 2 * a[2][c] - a[1][c];
        row[3]--;
        v[3][c] = false;
    }
    if (v[2][c])
    {
        a[2][c] = (a[1][c] + a[3][c]) / 2;
        row[2]--;
        v[2][c] = false;
    }
    col[c]--;
    cnt--;
}
