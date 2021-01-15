// solved

#include <fstream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
int deg[maxn];

ifstream fin("planting.in");
ofstream fout("planting.out");

int main()
{
  int N;

  int ans = -1;

  fin >> N;
  for (int i = 0; i < N - 1; ++i)
  {
    int a, b;
    fin >> a >> b;
    deg[a]++;
    deg[b]++;
    ans = max(ans, deg[a]);
    ans = max(ans, deg[b]);
  }

  fout << ans + 1 << '\n';

  return 0;
}
