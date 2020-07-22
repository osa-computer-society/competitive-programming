#include <iostream>
#define MAXCANDIDATES 10
#define NMAX 10
using namespace std;

bool finished = false;

bool is_a_solution (int a[], int k, int n)
{
    return k == n;
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void process_solution(int a[], int k, int n)
{
    cout << '{';
    for (int i = 1; i <= k; i++)
        if (a[i])
            cout << ' ' << i;
    cout << " }\n";
}

/**
 * @param a the array of processed elements
 * @param k the number of elements in a
 * @param n the total number of elements in the set
 */
void backtrack(int a[], int k, int n)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;

    if (is_a_solution(a, k, n))
        process_solution(a, k, n);
    else
    {
        k += 1; // increment the length of a
        construct_candidates(a, k, n, c, &ncandidates);
        for (int i = 0; i < ncandidates; i++)
        {
            // for each of the candidates for the next
            // value, we set the next term in a to be that
            // value
            a[k] = c[i];
            backtrack(a, k, n);
            if (finished) return;
        }
    }
}

void generate_subsets(int n)
{
    int a[NMAX];

    backtrack(a, 0, n);
}

int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    generate_subsets(n);
}
