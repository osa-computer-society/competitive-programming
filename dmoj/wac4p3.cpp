// Problem ID: wac4p3.cpp
// By Alexander Cai

#include <iostream>
#define MAXN 16
using namespace std;
typedef pair<int,int> pii;

pii pos[MAXN], vel[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> pos[i].first >> pos[i].second >> vel[i].first >> vel[i].second;
    }

    return 0;
}
