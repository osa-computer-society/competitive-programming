// Problem ID: 
// By 

#include <fstream>
#include <cstring>
#define MAXN 100005
using namespace std;

int f[MAXN], s[MAXN], taken[MAXN][3], ans[MAXN], cnt;

void move_to_second(int cow)
{
    // cow's first choice is taken by new cow
    int t = s[cow];
    taken[f[cow]][1] = 0;
    if (taken[t][1]) move_to_second(taken[t][1]);
    else if (!taken[t][2]) cnt++;
    taken[t][2] = cow;
}

int main()
{
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");

    int N, M;
    fin >> N >> M;

    for (int i = 1; i <= N; i++) fin >> f[i] >> s[i];

    memset(taken, 0, sizeof(taken));

    for (int cow = N; cow >= 1; cow--)
    {
        int &hasf = taken[f[cow]][1], &hass = taken[f[cow]][2];
        if (!hasf && !hass)
        {
            cnt++;
        }
        else if (hasf)
        {
            move_to_second(hasf);
        }
        else if (hass)
        {
            hass = 0;
        }
        hasf = cow;
        ans[cow] = cnt;
    }

    for (int i = 1; i <= N; i++) fout << ans[i] << '\n';

    fin.close();
    fout.close();

    return 0;
}
