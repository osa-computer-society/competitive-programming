#include <iostream>
#include <vector>

using namespace std;

vector<int> sortEvenOdd(vector<int> &nums)
{
    vector<int> evens;
    vector<int> odds;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i & 1)
            odds.push_back(nums[i]);
        else
            evens.push_back(nums[i]);
    }
    sort(evens.begin(), evens.end(), greater<int>());
    sort(odds.begin(), odds.end());
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i & 1)
        {
            ans.push_back(odds.back());
            odds.pop_back();
        }
        else
        {
            ans.push_back(evens.back());
            evens.pop_back();
        }
    }

    return ans;
}

int main()
{
    vector<int> nums{2, 1};

    for (int x : sortEvenOdd(nums))
    {
        cout << x << '\n';
    }

    return 0;
}