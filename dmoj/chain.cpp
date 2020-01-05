// Problem ID: chain
// By Alexander Cai
// Solved 4 Jan 2020

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    int gl[N], gr[N], sl[N], sr[N], pg = -1, leng = -1, ps = -1, lens = -1;
    memset(gl, 0, sizeof(gl));
    memset(gr, 0, sizeof(gr));
    memset(sl, 0, sizeof(sl));
    memset(sr, 0, sizeof(sr));
    char c;
    for (int i = 0; i < N; i++)
    {
        cin >> c;
        if (c == 'p' || c == 'g')
        {
            if (pg == -1) pg = i, leng = 1;
            else leng++;
            gl[i] = leng;
        }
        else if (pg >= 0)
        {
            for (int j = pg, k = leng; j < pg+leng; j++, k--)
                gr[j] = k;
            pg = -1;
        }

        if (c == 'p' || c == 's')
        {
            if (ps == -1) ps = i, lens = 1;
            else lens++;
            sl[i] = lens;
        }
        else if (ps >= 0)
        {
            for (int j = ps, k = lens; j < ps+lens; j++, k--)
                sr[j] = k;
            ps = -1;
        }
    }
    if (pg >= 0) for (int i = pg, k = leng; i < pg+leng; i++, k--) gr[i] = k;
    if (ps >= 0) for (int i = ps, k = lens; i < ps+lens; i++, k--) sr[i] = k;
    if (gl[N-1] == N || sl[N-1] == N)
    {
        cout << N << '\n';
        return 0;
    }
    if (gr[0] && gl[N-1])
    {
        int total = gr[0] + gl[N-1];
        for (int i = gr[0]-1, k = total; k > 0; i = (i-1+N)%N, k--)
            gl[i] = k, gr[i] = total - k + 1;
    }
    if (sr[0] && sl[N-1])
    {
        int total = sr[0] + sl[N-1];
        for (int i = sr[0]-1, k = total; k > 0; i = (i-1+N)%N, k--)
            sl[i] = k, sr[i] = total - k + 1;
    }

    int val = 0;
    for (int i = 0; i < N; i++)
    {
        // cout << gl[i] << ' ' << gr[i] << "   " << sl[i] << ' ' << sr[i] << '\n';
        val = max(val, gl[i]+gr[(i+1)%N]);
        val = max(val, sl[i]+sr[(i+1)%N]);
        val = max(val, gl[i]+sr[(i+1)%N]);
        val = max(val, sl[i]+gr[(i+1)%N]);
        // cout << val << '\n' << '\n';
    }

    cout << min(val, N) << '\n';

    return 0;
}
