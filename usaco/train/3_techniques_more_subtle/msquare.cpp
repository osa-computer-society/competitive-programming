/*
ID: a.cai61
TASK: msquare
LANG: C++14
*/

// solved 2020-09-21

// man, I found this one really hard, spent like 2 hours on it
// bfs, hash, backtrack

#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef int seq[10];

ifstream fin("msquare.in");
ofstream fout("msquare.out");

seq tform[4] = {
    {},
    {0, 8, 7, 6, 5, 4, 3, 2, 1},
    {0, 4, 1, 2, 3, 6, 7, 8, 5},
    {0, 1, 7, 2, 4, 5, 3, 6, 8}};
map<int, int> dist; // dist[k] = number of transformations it takes to get from k to the target sequence

int encode(seq s)
{
    int total = 0;
    FOR(i, 8)
    {
        total += s[i]-1;
        if (i < 8) total *= 8;
    }
    return total;
}

void decode(int *s, int e)
{
    FOR(i, 8)
        s[9 - i] = e % 8 + 1, e /= 8;
}

int main()
{
    seq target;
    FOR(i, 8)
        fin >> target[i];

    seq s = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    int inite = encode(s);
    seq ss;
    queue<int> Q;

    int e = encode(target);
    int ee;
    dist[e] = 0;
    Q.push(e);
    while (!Q.empty())
    {
        e = Q.front();
        Q.pop();
        if (e == inite) // found it!
            break;
        decode(s, e);
        FOR(t, 3) // each kind of transformation
        {
            // reverse transform, i.e. ss is a state which turns into s under transformation t
            FOR(i, 8)
                ss[tform[t][i]] = s[i];
            ee = encode(ss);
            if (dist.find(ee) == dist.end()) // don't add this node if it's already processed
            {
                dist[ee] = dist[e] + 1;
                Q.push(ee);
            }
        }
    }

    fout << dist[inite] << '\n';
    e = inite;
    decode(s, e);
    // stop once dist[e] == 0
    while (dist[e] > 0)
    {
        // for each transformation
        FOR(t, 3)
        {
            // forward transform, i.e. ss is the result when you use transform t on s
            FOR(i, 8)
                ss[i] = s[tform[t][i]];
            ee = encode(ss);
            if (dist[ee] == dist[e] - 1)
            {
                // print the type of transformation
                fout << (char) ('A' - 1 + t);
                e = ee;
                decode(s, e);
                break;
            }
        }
    }

    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
