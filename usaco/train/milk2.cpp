/*
ID: a.cai61
TASK: milk2
LANG: C++14
*/

// solved 2020-07-19

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int N;
    fin >> N;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 0, a, b; i < N; i++)
    {
        fin >> a >> b;
        pq.push(make_pair(a, b));
    }

    pii prev = pq.top(); pq.pop();
    int idle = 0, cont = prev.second - prev.first;
    while (!pq.empty())
    {
        pii curr = pq.top(); pq.pop();
        cout << curr.first << ' ' << curr.second << '\n';
        if (curr.first > prev.second) // begins after the prev ends => idle
        {
            idle = max(idle, curr.first - prev.second);
            cont = max(cont, curr.second - curr.first);
            prev = curr;
        }
        else
        {
            cont = max(cont, curr.second - prev.first);
            prev.second = max(prev.second, curr.second);
        }
    }
    fout << cont << ' ' << idle << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
