#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    vector<int> stack;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        if (n == 0)
            stack.pop_back();
        else
            stack.push_back(n);
    }

    int total(0);
    for (int j : stack)
        total += j;

    cout << total << endl;
}