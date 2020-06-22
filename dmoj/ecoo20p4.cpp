// Problem ID: ecoo20p4.cpp
// By Alexander Cai

#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll MOD = 1e9 + 7;

map<string,pll> funcs;
ll m, b, i;
string s, ss;
int cnt;

void ring(string s, ll &m, ll &b)
{
    if (s == "ADD")
    {
        cin >> i;
        b = (b+i)%MOD;
    }
    else if (s == "SUB")
    {
        cin >> i;
        b = (b-i+MOD)%MOD;
    }
    else if (s == "MULT")
    {
        cin >> i;
        m = (m*i)%MOD, b = (b*i)%MOD;
    }
    else if (s == "FUN")
    {
        cin >> s;
        // cout << "ENTERING " << s << "\n";
        ll mm = 1, bb = 0;
        while (true)
        {
            cin >> ss;
            cnt++;
            if (ss == "END") break;
            ring(ss, mm, bb);
        }
        // cout << "PARAMS: " << mm << ' ' << bb << '\n';
        funcs[s] = make_pair(mm%MOD, bb%MOD);
    }
    else if (s == "CALL")
    {
        cin >> s;
        ll mm = funcs[s].first, bb = funcs[s].second;
        // cout << "CALLING " << s << ": " << mm << ' ' << bb << '\n';
        m = (m*mm)%MOD;
        b = (mm * b + bb)%MOD;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin >> _;

    int N;
    ll m, b;
    string s;
    while (_--)
    {
        cin >> N;
        m = 1, b = 0, cnt = 0;
        while (cnt < N)
        {
            cin >> s;
            cnt++;
            ring(s, m, b);
            // cout << m << ' ' << b << '\n';
        }
        if (b < 0)
        {
            ll n = abs(b) / MOD + 1;
            b += n*MOD;
        }
        cout << b % MOD << '\n';
    }

    return 0;
}
