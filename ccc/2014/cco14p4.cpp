// Problem ID: cco14p4.cpp
// By 

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

vector<pii> graph;

bool cmp(pii a, pii b)
{
  return a.second < b.second;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, P;
    cin >> N >> P;
    
    int fuel = 0, cnt = 1;

    for (int i = 0, a, b; i < N; i++)
    {
      cin >> a >> b;
      if (i == P-1)
      {
        fuel = a;
        continue;
      }
      if (a < b) continue;
      graph.push_back({a, b});
    }

    sort(graph.begin(), graph.end(), cmp);

    for (pii p : graph)
    {
      if (fuel >= p.second)
      {
        fuel += p.first - p.second;
        cnt++;
      }
      else break;
    }

    cout << fuel << '\n' << cnt << '\n';

    return 0;
}
