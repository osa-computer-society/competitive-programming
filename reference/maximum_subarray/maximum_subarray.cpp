/**
 * @file maximum_subarray.cpp
 * @author Alexander Cai
 * @brief An implementation of the maximum subarray problem
 * @date 2022-02-13
 * 
 * See CLRS 4.1
 */

#include <iostream>
#include <limits>
#include <vector>

// let n be number of entries high - low + 1
// then theta(n) time
int64_t find_max_crossing_subarray(
    const std::vector<int32_t> &arr,
    size_t low, size_t mid, size_t high,
    size_t *max_left, size_t *max_right)
{
    // find max subarray of left half, arr[low..mid]
    // of the form arr[i..mid] where low <= i <= mid
    int64_t left_sum = std::numeric_limits<int64_t>::min();
    int64_t sum = 0;
    for (size_t i = mid; i >= low; --i)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            *max_left = i;
        }
    }

    int64_t right_sum = std::numeric_limits<int64_t>::min();
    sum = 0;
    for (size_t i = mid + 1; i <= high; ++i)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            *max_right = i;
        }
    }
    return left_sum + right_sum;
}

int64_t find_maximum_subarray(
    const std::vector<int32_t> &arr,
    size_t low, size_t high,
    size_t *left, size_t *right)
{
    // one element
    if (high == low)
    {
        *left = *right = low;
        return arr[low];
    }
    else
    {
        size_t mid = (low + high) / 2; // floor
        size_t left_low, left_high, right_low, right_high, cross_low, cross_high;
        int64_t left_sum, right_sum, cross_sum;
        left_sum = find_maximum_subarray(arr, low, high, &left_low, &left_high);
        right_sum = find_maximum_subarray(arr, low, high, &right_low, &right_high);
        cross_sum = find_max_crossing_subarray(arr, low, mid, high, &cross_low, &cross_high);

        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            *left = left_low;
            *right = left_high;
            return left_sum;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum)
        {
            *left = right_low;
            *right = right_high;
            return right_sum;
        }
        else
        {
            *left = cross_low;
            *right = cross_high;
            return cross_sum;
        }
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int32_t> arr(n);

    for (size_t i = 1; i <= n; ++i)
        std::cin >> arr[i];

    size_t left, right;
    int64_t sum = find_maximum_subarray(arr, 1, n, &left, &right);

    std::cout << "left: " << left << '\n';
    std::cout << "right: " << right << '\n';
    std::cout << "sum: " << sum << '\n';

    return 0;
}