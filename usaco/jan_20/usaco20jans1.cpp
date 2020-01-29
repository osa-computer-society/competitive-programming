// Problem ID: 
// By 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

int B[1005], K;
vector<int> baskets;

int solve(int i, int rem)
{
    if (rem == 0)
    {
        sort(baskets.begin(), baskets.end());
        int total = 0;
        for (int k = 0; k < K / 2; k++)
            total += baskets[k];
        return total;
    }
    
    int ans = -1;
    
    for (int j = 1; j <= rem; j++) // j is number of baskets we split this one into
    {
        for (int k = 0; k < j; k++)
            baskets.push_back(B[i] / j);
        baskets.back() += B[i] % j;
        
        ans = max(ans, solve(i-1, rem-j));
        
        for (int k = 0; k < j; k++)
            baskets.pop_back();
    }

    return ans;
}

int main()
{
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    memset(dp, -1, sizeof(dp));

    int N;
    fin >> N >> K;
    for (int i = 1; i <= N; i++)
        fin >> B[i];

    sort(B+1, B+N+1);

    fout << solve(N, K) << '\n';

    return 0;
}
