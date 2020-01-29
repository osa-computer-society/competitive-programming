#include <iostream>
#define MAXSUM 1000000000
using namespace std;

int N, M;
bitset<MAXSUM> bit;

bool processQueries(int query[], int nq)
{
    // One by one process subset sum queries
    for (int i = 0; i < nq; i++)
    {
       int x = query[i];
       // If x is beyond size of bit[]
       if (x >= MAXSUM)
       {
           cout << "NA, ";
           continue;
       }
       // Else if x is a subset sum, then x'th bit
       // must be set
       return bit[x];
    }
}

// function to store all the subset sums in bit vector
void preprocess(bitset<MAXSUM> &bit, int arr[], int n)
{
    bit.reset();
    bit[0] = 1;
    for (int i : arr)
        // Do OR of following two
        // 1) All previous sums. We keep previous value
        //    of bit.
        // 2) arr[i] added to every previous sum. We
        //    move all previous indexes arr[i] ahead.
        bit |= (bit << i);
}
// Driver program
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    preprocess(bit, arr, n);
    processQueries(query, nq);
    return 0;
}
