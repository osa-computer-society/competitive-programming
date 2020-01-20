/*
ID: a.cai61
TASK: milk2
LANG: C++14
*/

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

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0, a, b; i < N; i++)
    {
        fin >> a >> b;
        pq.push({a,1});
        pq.push({b,-1});
    }

    int stack = 0, idle = 0, cont = 0, prev = pq.top().first;
    while (!pq.empty())
    {
        int n = pq.top().first; int t = pq.top().second; pq.pop();
        cout << n << ' ' << t << '\n';
        if (!pq.empty() && n == pq.top().first)
        {
            if (t == pq.top().second)
                stack += t == 1 ? 1 : -1;
            pq.pop();
            continue;
        }
        if (t == 1)
        {
            if (stack == 0)
                idle = max(idle, n - prev), prev = n;
            stack++;
        }
        else
        {
            stack--;
            if (stack == 0)
                cont = max(cont, n-prev), prev = n;
        }
    }

    fout << cont << ' ' << idle << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
