// LeetCode
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// int findMaxLength(vector<int> &nums) // Brute Force
// {
//     int curr_sum = 0;
//     int one = 0;
//     int zero = 0;
//     int max_len = 0;
//     int n = nums.size();

//     for (int i = 0; i < n; i++)
//     {
//         curr_sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             curr_sum += nums[j];
//             one = curr_sum;
//             zero = j - i + 1 - one;
//             if (one == zero)
//                 max_len = max(max_len, j - i + 1);
//         }
//     }

//     return max_len;
// }

// int findMaxLength(vector<int> &nums) // Try...
// {
//     int max_len = 0;
//     int n = nums.size();
//     int sum = 0;
//     vector<int> v1;
//     vector<int> v0;

//     for (int i = 0; i < n; i++)
//     {
//         sum += nums[i];
//         v1.push_back(sum);
//         v0.push_back(i + 1 - sum);
//     }

//     // for (int i = 0; i < n; i++)
//     //     cout << v1[i] << " ";
//     // cout << endl;
//     // for (int i = 0; i < n; i++)
//     //     cout << v0[i] << " ";
//     // cout << endl;

//     for (int i = 1; i < n; i++)
//     {
//         int j = 0;
//         if (v1[i] == v0[i])
//             max_len = max(max_len, i + 1);
//         // else if(v1[i] != v0[i])
//         // {
//         //     j++;
//         // }
//         while ((v1[i] - v1[j]) != (v0[i] - v0[j]) && j < n && j < i)
//         {
//             if ((i - j) % 2 == 1)
//             {
//                 j++;
//                 continue;
//             }
//             j++;
//         }
//         if ((v1[i] - v1[j]) == (v0[i] - v0[j]))
//             max_len = max(max_len, i - j);
//     }

//     return max_len;
// }

// Idea: Make a variable 'count=0'. Increment it when we get 1 and decrement it when we get 0, by 1.
// int findMaxLength(vector<int> &nums) // Try...
// {
//     int max_len = 0;
//     vector<int> count(nums.size(), 0);
//     unordered_map<int, int> m; // <count, index>

//     int curr_sum = 0;
//     int one = 0;
//     int zero = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {

//         curr_sum += nums[i];
//         one = curr_sum;
//         zero = i + 1 - one;
//         if (one == zero)
//             max_len = max(max_len, i + 1);
//     }

//     if (nums.size() == 2)
//     {
//         if ((nums[0] == 0 && nums[1] == 1) || (nums[0] == 1 && nums[1] == 0))
//             return 2;
//         else
//             return 0;
//     }

//     if (nums[0] == 0)
//         count[0] = count[0] - 1;
//     else
//         count[0] = count[0] + 1;
//     m[count[0]] = 0;

//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] == 0)
//             count[i] = count[i - 1] - 1;
//         else
//             count[i] = count[i - 1] + 1;

//         if (!m.count(count[i])) // if count[i] is not present in map 'm'.
//             m[count[i]] = i;
//     }

//     // for (int i = 0; i < nums.size(); i++)
//     //     cout << count[i] << " ";
//     // cout << endl;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         // cout << count[i] << " " << m.at(count[i]) << endl;
//         if (m.count(count[i]))
//             max_len = max(max_len, i - m.at(count[i]));
//     }

//     return max_len;
// }

// int findMaxLength(vector<int> &nums) // 20-08-22
// Polish the last approach...
// // Time complexity: O(n); Space complexity: O(n)…because of the hash map.
// {
//     int max_len = 0;
//     int count = 0;
//     unordered_map<int, int> m; // <count, index>
//     m[0] = -1;                 // when subarray starts with index 0.
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == 0)
//             count = count - 1;
//         else
//             count = count + 1;

//         if (m.count(count))
//             max_len = max(max_len, i - m.at(count));
//         else
//             m[count] = i;
//     }

//     return max_len;
// }

int findMaxLength(vector<int> &nums) // 9-11-22
// Time complexity: O(n); Space complexity: O(n)…because of the hash map.
{
    // Idea: In the array of 0's and 1's, replace all 0's with -1.
    unordered_map<int, int> m;
    int preSum = 0, len = 0;
    int N = nums.size();

    for (int i = 0; i < N; i++)
    {
        if (nums[i] == 0)
            nums[i] = -1;
        preSum += nums[i];
        if (preSum == 0)
            len = i + 1;
        if (m.find(preSum) != m.end())
            len = max(len, i - m[preSum]);
        if (m.find(preSum) == m.end())
            m.insert({preSum, i});
    }

    return len;
}

int main()
{
    // vector<int> A = {0, 1, 1, 0, 0, 1, 0, 0, 1, 1}; // o/p: 10
    // vector<int> A = {0, 0, 0, 1, 1, 1, 0}; // o/p: 6
    // vector<int> A = {0, 1, 0}; // o/p: 2
    // vector<int> A = {1, 1, 0, 1, 0, 1, 1}; // o/p: 4
    vector<int> A = {1, 1, 0, 0, 1}; // o/p: 4
    // vector<int> A = {0, 1}; // o/p: 2

    cout << "maxLen = " << findMaxLength(A);

    return 0;
}