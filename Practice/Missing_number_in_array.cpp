// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
// 1 ≤ N ≤ 10^6 means O(nlogn)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int MissingNumber(vector<int> &array, int n) // My approach: O(nlogn)
// {
//     sort(array.begin(), array.end()); // Nlog(N)
//     int count = 0;
//     for (int i = 0; i < n; i++) // O(N)
//     {
//         count++;
//         if (array[i] != count)
//             return count;
//     }
// }

int MissingNumber(vector<int> &array, int n) // Optimized: O(n)
{
    // int sumTotal = (n+1)*(n+2)/2; // integer overflow // n is array size

    /*Approach 1 - Two separate for loops*/
    // int sumTotal = 0;
    // for (int i = 1; i <= (n + 1); i++)
    // {
    //     sumTotal = sumTotal + i;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     sumTotal = sumTotal - array[i];
    // }
    // return sumTotal;

    /*Approach 2 - Only one single for loop*/
    int sumTotal = 1;
    for (int i = 2; i <= (n + 1); i++)
    {
        sumTotal = sumTotal + i;
        sumTotal = sumTotal - array[i - 2];
    }
    return sumTotal;
}

int main()
{
    vector<int> v{1, 2, 4, 6, 3, 7, 8};
    cout << MissingNumber(v, 7);

    return 0;
}