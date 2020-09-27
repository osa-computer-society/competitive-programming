// solved

// binary search for the solution

#include <iostream>
#include <math.h>
#define MAXN 100005
using namespace std;

int M[MAXN];

int main()
{
    int T;
    cin >> T;
    int N; // # workouts
    int K; // # inserts
    for (int i = 1; i <= T; i++)
    {
        cin >> N >> K;
        for (int j = 1; j <= N; j++)
            cin >> M[j];

        int lo = 1, hi = 1e9;
        // break when lo == hi == optimal difference
        while (lo < hi)
        {
            int mi = (lo + hi) / 2; // optimal difference to try
            
            int k = 0; // # workouts that need to be inserted
            for (int i = 1; i < N; i++)
                k += ceil((double) (M[i+1]-M[i]) / (double) mi) - 1;

            // if we have too many workouts, we need to increase the optimal difference
            if (k > K)
                lo = mi+1;
            // this optimal difference is valid, so we try to make it smaller
            else if (k <= K)
                hi = mi;
        }
        cout << "Case #" << i << ": " << lo << "\n";
    }
    return 0;
}