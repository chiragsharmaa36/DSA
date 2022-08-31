// Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

// Constraints:

// 1 <= n <= 10^5
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int rep;
    sort(nums.begin(), nums.end()); // nlog(n)

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            rep = nums[i];
            break;
        }
    }

    return rep;
}