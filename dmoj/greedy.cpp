// Problem ID: greedy
// By Alexander Cai 31 Dec 2019

#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#define MAXN 200005
using namespace std;
typedef pair<int,int> pii;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int N, M, p, a;
  vector<pii> factories;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> p >> a;
    factories.push_back(make_pair(p, a));
  }
  sort(factories.begin(), factories.end(), greater_equal<pii>());
  pii temp;
  long long total = 0;
  while (M > 0)
  {
    temp = factories.back(); factories.pop_back();
    if (temp.second <= M)
    {
      M -= temp.second;
      total += temp.first * temp.second;
    }
    else
    {
      total += temp.first * M;
      break;
    }
  }

  cout << total << '\n';

  return 0;
}
