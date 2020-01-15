// Problem ID: 
// By 

#include <iostream>
#include <vector>
#include <string>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

vector<string> A;
string B[22];
int max_len, l, k, N;

bool valid()
{
    int total;
    for (int i = 0; i < max_len; i++)
    {
        total = 0;
        for (int j = 0; j < k; j++)
            total += B[j][i] - '0';
        if (total > 9) return 0;
    }
    return 1;
}

void ans(int i)
{
    if (i == N) return;
    if (valid()) l = max(l, k);
    else return;
    for (int j = i+1; j < N; j++)
    {
        B[k] = A[j];
        k++;
        ans(j);
        k--;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    scan(N);
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i], max_len = max(max_len, (int) A[i].size());
    for (int i = 0; i < N; i++)
        A[i] = string(max_len-A[i].size(), '0').append(A[i]);
    ans(-1);
    cout << l << '\n';

    return 0;
}
