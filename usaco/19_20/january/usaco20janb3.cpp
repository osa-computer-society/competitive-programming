// Problem ID: 
// By 

#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int K, N;
    cin >> K >> N;

    for (int i = 0, X; i < N; i++)
    {
        cin >> X;

// for each minimum speed X:
int speed = 0, elapsed = 0, traveled = 0;
while (true)
{
    // while speeding up
    speed++;
    elapsed++;
    traveled += speed;
    if (traveled >= K)
    {
        cout << elapsed << '\n';
        break;
    }
    if (speed < X) continue;
    // while slowing down
    traveled += speed;
    elapsed++;
    if (traveled >= K)
    {
        cout << elapsed << '\n';
        break;
    }
}

    }

    return 0;
}
