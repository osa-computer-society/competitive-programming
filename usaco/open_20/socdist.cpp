// Problem ID: 
// By 

#include <iostream>
#include <fstream>
#define MAXN 100005
using namespace std;

long long pos[MAXN], freq[MAXN];

int main()
{
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");

    int N, M;
    fin >> N >> M;

    long long maxb = -1;
    long long tot = M;

    long long a, b;
    for (int i = 1; i <= M; i++)
    {
      fin >> a >> b;
      pos[a]=i, pos[b+1]=-i, freq[i] = b-a;
      tot += freq[i];
      maxb = max(maxb, b);
    }
    // cout << tot << '\n';

    for (int i = 1; i <= maxb; i++)
      pos[i] = pos[i-1]+pos[i];

    long long maxd = maxb / (N-1);

    fout << maxd << '\n';

    return 0;
}
