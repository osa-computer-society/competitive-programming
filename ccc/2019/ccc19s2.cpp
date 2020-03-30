// Problem ID: 
// By Alexander Cai

#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i = 5; i*i<=n; i += 6)
        if (n%i == 0 || n%(i+2)==0)
            return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0, x; i < N; i++)
    {
        cin >> x;
        int a = x;
        while (true)
        {
            if (is_prime(a) && is_prime(2*x-a))
            {
                cout << a << ' ' << 2*x-a << '\n';
                break;
            }
            a--;
        }
    }

    return 0;
}
