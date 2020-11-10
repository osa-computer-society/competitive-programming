// solved 2020-09-20

// sliding window

#include <iostream>
#include <fstream>
#include <vector>
#define FOR(i, n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef pair<int,int> pii;

ifstream fin("contact.in");
ofstream fout("contact.out");

int freq[15][1 << 13];
int val[15];
vector<pii> ans[200000];

void printbin(int len, int bin)
{
    if (len == 0) return;
    printbin(len-1, bin >> 1);
    fout << (bin & 1);
}

int main()
{
    int A, B, N;
    fin >> A >> B >> N;

    int i = 0;
    char c;
    while (fin >> c)
    {
        ++i;
        c = c - '0'; // get numerical value
        if (i < A)
        {
            val[A] = (val[A] << 1) | c;
            continue;
        }
        // incrementally add to val
        for (int len = min(i, B); len >= A; --len)
        {
            int &bits = val[len];
            if (i == len && i != A) bits = (val[len-1] << 1) | c;
            else bits = ((bits << 1) & ((1 << len) - 1)) | c;
            ++freq[len][bits];
        }
    }

    int cnt = 0, max_freq = -1;
    // len = the length of the sequence
    for (int len = A; len <= B; ++len)
    {
        // bits = the numerical value of the sequence
        for (int bits = 0; bits <= (1 << len) - 1; ++bits)
        {
            // if this sequence exists
            if (freq[len][bits] > 0)
            {
                // we add it to the list of sequences with the same frequency as it
                ans[freq[len][bits]].push_back(make_pair(len, bits));
                max_freq = max(max_freq, freq[len][bits]);
            }
        }
    }

    // check each possible frequency in decreasing order and print the top N
    for (int f = max_freq, j = 1; f > 0 && j <= N; --f)
    {
        // skip if no sequences have this frequency
        if (ans[f].size() == 0) continue;
        fout << f << '\n';
        for (int k = 0, tab = 0; k < ans[f].size(); ++k, ++tab)
        {
            if (tab > 0) fout << (tab % 6 == 0 ? '\n' : ' ');
            printbin(ans[f][k].first, ans[f][k].second);
        }
        ++j;
        fout << '\n';
    }
    
    fin.close();
    fout.close();
    return 0;
}
