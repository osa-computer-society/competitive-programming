/*
ID: a.cai61
TASK: zerosum
LANG: C++14
*/

// solved

// simple backtracking, recursion

#include <iostream>
#include <fstream>
#include <vector>
#define SPACE 1
#define ADD 2
#define SUB 3
using namespace std;

int N;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int op[15]; // op[n] is the operator after n

void rec(int n, int val)
{
    if (n == N)
    {
        if (val == 0)
        {
            for (int i = 1; i < N; ++i)
            {
                fout << i;
                if (op[i] == SPACE) fout << ' ';
                else if (op[i] == ADD) fout << '+';
                else if (op[i] == SUB) fout << '-';
            }
            fout << N << '\n';
        }
        return;
    }

    if (op[n-1] != SPACE)
    {
        op[n] = SPACE;
        if (op[n-1] == ADD || n == 1)
            rec(n+1, val + n*10 + 1);
        else if (op[n-1] == SUB)
            rec(n+1, val - n*10 - 1);
    }
    op[n] = ADD;
    rec(n+1, val + n+1);
    op[n] = SUB;
    rec(n+1, val - n-1);
}

int main()
{
    fin >> N;

    rec(1, 1);

    fin.close();
    fout.close();
    return 0;
}
