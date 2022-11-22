#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string winner, name;
    int highestbid = -1, bid;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> bid;
        if (bid > highestbid)
        {
            winner = name;
            highestbid = bid;
        }
    }
    cout << winner << '\n';
    return 0;
}