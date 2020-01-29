// Problem ID: 
// By 

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ifstream fin("loan.in");
    ofstream fout("loan.out");

    ll N, K, M;
    fin >> N >> K >> M;

    ll X = 1;
    while (true)
    {
        ld r = (ld)(X-1)/X;
        // cout << "r: " << r << ", X: " << X << ", M: " << M << ", N: " << N << '\n';
        ll cnt = ceil(log2((ld)X*M/N) / log2(r));
        // cout << (ld)N / X << '\n';
        ll sum = (ld)(N/X) * (1.0-pow(r, cnt)) / (1.0-r);
        cnt += ceil((N-sum)/M);
        if (cnt > K)
        {
            fout << X << '\n';
            return 0;
        }
        cout << cnt << '\n';
        break;
        X++;
    }

    return 0;
}
