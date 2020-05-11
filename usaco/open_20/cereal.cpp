// Problem ID: 
// By 

#include <iostream>
#include <cstring>
#include <utility>
#define MAXN 100005
using namespace std;
typedef pair<int,int> pii;

int who_has[MAXN], ans[MAXN], cnt = 0;
pii cow[MAXN];

void move_to_second(int i)
{
  int &cow2 = who_has[cow[i].second];
  if (!cow2)
    cow2 = i, cnt++;
  if (cow2 <= i) return;
  else {
    if (cow[i].second == cow[cow2].first)
    {
      int temp = cow2;
      cow2 = i;
      move_to_second(temp);
    }
    else if (cow[i].second == cow[cow2].second)
    {
      cow2 = i;
    }
  }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> cow[i].first >> cow[i].second;

    for (int i = N; i >= 1; i--)
    {
      int &who_has_first_choice = who_has[cow[i].first];
      if (!who_has_first_choice)
        cnt++;
      else // someone has the new cow's first choice
        move_to_second(who_has_first_choice);

      who_has_first_choice = i;
      ans[i] = cnt;
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';

    return 0;
}
