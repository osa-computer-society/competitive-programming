// By Alexander Cai

// O(N)

#include <iostream>
#include <string>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;

const int L = 0, M = 1, S = 2;

int in[3][3];

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    s = " " + s; // for index at 1
    int NL = 0, NM = 0, NS = 0;

    // count numner of characters in each section

    FOR(i, 1, N)
    {
        if (s[i] == 'L')
            NL++;
        else if (s[i] == 'M')
            NM++;
        else
            NS++;
    }

    FOR(i, 1, NL)
    {
        if (s[i] == 'L')
            in[L][L]++;
        else if (s[i] == 'M')
            in[M][L]++;
        else
            in[S][L]++;
    }

    FOR(i, NL + 1, NL + NM)
    {
        if (s[i] == 'L')
            in[L][M]++;
        else if (s[i] == 'M')
            in[M][M]++;
        else
            in[S][M]++;
    }

    FOR(i, NL + NM + 1, N)
    {
        if (s[i] == 'L')
            in[L][S]++;
        else if (s[i] == 'M')
            in[M][S]++;
        else
            in[S][S]++;
    }

    int nswaps = 0;

    int swaps = min(in[M][L], in[L][M]);
    nswaps += swaps;
    in[M][L] -= swaps, in[L][M] -= swaps;

    swaps = min(in[S][L], in[L][S]);
    nswaps += swaps;
    in[S][L] -= swaps, in[L][S] -= swaps;

    // now, consider cycles
    // put all M from L section into S section
    nswaps += in[L][S];
    in[L][L] += in[L][S];
    in[L][S] = 0;
    in[M][S] += in[M][L];
    in[M][L] = 0;

    // put all S from L section into M section
    nswaps += in[L][M];
    in[L][L] += in[L][M];
    in[L][M] = 0;
    in[S][M] += in[S][L];
    in[S][L] = 0;

    // remaining S and M swaps
    nswaps += in[S][M];

    cout << nswaps << '\n';

    return 0;
}
