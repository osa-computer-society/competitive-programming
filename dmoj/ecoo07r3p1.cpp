// Problem ID: 
// By 

#include <iostream>
#include <cmath>
#include <cstring>
#define MAXN 10000005
using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0, n; i < 5; i++)
    {
        cin >> n;
        cout << n << " = ";
        if (is_prime(n)) cout << n << '\n';
        else if (n % 2 == 0)
        {
            for (int k = n / 2; k >= 3; k--)
                if (is_prime(k) && is_prime(n-k))
                {
                    cout << k << " + " << n-k << '\n';
                    break;
                }
        }
        else
        {
            for (int k = n / 3; k >= 3; k--)
            {
                if (!is_prime(k)) continue;
                for (int j = (n-k)/2; j >= 3; j--)
                    if (is_prime(j) && is_prime(n-k-j) && j >= k)
                    {
                        cout << k << " + " << j << " + " << n-k-j << '\n';
                        k = 2;
                        break;
                    }
            }
        }
    }

    return 0;
}
