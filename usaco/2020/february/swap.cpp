#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 100005
#define MAXM 105
using namespace std;

int L[MAXM], R[MAXM], x[MAXN], diff[MAXN], prevx[MAXN], curr[MAXN];

int main()
{
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    int N, M, K;
    fin >> N >> M >> K;
    
    for (int i = 1; i <= N; i++)
        x[i] = i;

    for (int i = 1; i <= M; i++)
        fin >> L[i] >> R[i];

    for (int j = 1; j <= M; j++)
        for (int k = L[j]; k <= ((L[j] + R[j]) >> 1); k++)
            swap(x[k], x[L[j]+R[j]-k]);

    for (int i = 1; i <= N; i++)
    {
        diff[x[i]] = i - x[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cout << diff[i] << '\n';
    }

    
    
    for (int i = 1; i <= N; i++)
        fout << curr[i] << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
