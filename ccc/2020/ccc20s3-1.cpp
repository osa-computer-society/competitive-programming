// Solved Alexander Cai 2021-02-15
// with help from https://github.com/AndrewDongAndy/dmoj-solutions/blob/master/CCC/2020/ccc20s3_Hashing.cpp

// a perm. of N is a substring of H if the character frequencies of N
// and the substring are the same.

#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const int NTESTS = 4;

// multiple bases and mods to avoid collisions
ll BASES[NTESTS] = {1429, 131, 857, 8999};
ll MODS[NTESTS] = {(ll)1e9 + 9, (ll)1e9 + 7, (ll)1e9 + 7, (ll)1e9 + 9};

// place_value[n] = the n'th character's place value, calculated for a specific mod and base
ll place_value[MAXN];
// psa[i][j] = character frequency of j from haystack[1..i]
int psa[MAXN][30];

string needle, haystack;
vector<int> needle_freq(26, 0);
int nsize, hsize;

// calculates # of unique substrings in haystack that are permutations of needle
// given a specific base and mod for hashing
int solve(ll base, ll mod);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> needle >> haystack;
    nsize = needle.size();
    hsize = haystack.size();

    // get character frequencies of needle string
    for (char c : needle)
        needle_freq[c - 'a']++;

    for (int i = 1; i <= hsize; ++i)
    {
        for (int j = 0; j < 26; ++j)
            psa[i][j] = psa[i - 1][j];
        psa[i][haystack[i - 1] - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < NTESTS; ++i)
        ans = max(ans, solve(BASES[i], MODS[i]));

    cout << ans << '\n';

    return 0;
}

int solve(ll base, ll mod)
{
    // calculate place value array
    place_value[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        place_value[i] = place_value[i - 1] * base % mod;

    // calculate hash of the haystack
    vector<ll> hsh(hsize + 1, 0);
    for (int i = 1; i <= hsize; ++i)
        hsh[i] = (base * hsh[i - 1] + haystack[i - 1]) % mod;

    // set of all substrings we encounter
    // recall we keep a SEPARATE set for each hash
    set<int> st;
    // i is the index of the first character of the needle
    for (int i = 0; i + nsize <= hsize; ++i)
    {
        // new array to get character frequencies from haystack[i..i+nsize)
        vector<int> substring_freq(26, 0);
        for (int j = 0; j < 26; ++j)
            substring_freq[j] = psa[i + nsize][j] - psa[i][j];

        // vector equality checks for equality of all elements
        // i.e. if character frequency in this substring of haystack
        // is the same as character frequency of needle
        if (substring_freq == needle_freq)
        {
            ll h = hsh[i + nsize] - place_value[nsize] * hsh[i];
            if (h < 0)
                h += mod;
            h = (h % mod + mod) % mod;
            st.insert(h); // this substring has already been seen
        }
    }
    return st.size();
}
