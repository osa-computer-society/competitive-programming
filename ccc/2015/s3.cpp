// Solved

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int G, P, k;
    cin >> G >> P;
    
    set<int> gates;
    for (int i = 1; i <= G; i++) gates.insert(-i); // negative so that we get greater than or equal to with lower_bound
    
    for (int i = 0; i < P; i++)
    {
        cin >> k;
        auto it = gates.lower_bound(-k);
        if (it == gates.end())
        {
            cout << i;
            return 0;
        }
        gates.erase(it);
    }

    cout << P;
    return 0;
}