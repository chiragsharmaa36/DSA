// Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
// In case of multiple subarrays, return the subarray which comes first on moving from left to right.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to find a continuous sub-array which adds up to a given number.

//Brute-Force
// vector<int> subarraySum(int arr[], int n, long long s) 
// {
    // vector<int> v;
    // int sum = 0;

    // for (int i = 0; i < n; i++)
    // {
    //         sum = arr[i];
    //     for(int j = i+1; j<n;j++)
    //     {
    //         sum += arr[j];
    //         if(sum == s)
    //         {
    //             v.push_back(i+1);
    //             v.push_back(j+1);
    //             break;
    //         }
    //     }
    //     if(v.size()==2)
    //         break;
    // }

//     return v;
// }

vector<int> subarraySum(int arr[], int n, long long s) // Optimized
{
    vector<int> v;
    int sum = 0;

    int i = 0; //starting
    int j = 0; //ending

    while (i <= j && (i<=n && j<=n)) // i <= j & i and j both are under the length of the given array.
    {
        sum = sum + arr[j];
        if (sum > s)
        {
            i++;
            sum = 0; // re-start from next starting point (i).
            j = i; // because a single element in an array is a sub-array.
        }
        else if (sum < s)
            j++; // keeping the starting point same, add the next ending point.
        else
        {
            v.push_back(i + 1);
            v.push_back(j + 1);
            break;
        }
    }

    if (v.size() != 2)
        v.push_back(-1);

    return v;
}
int main()
{
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[5] = {1, 2, 3, 7, 5};
    vector<int> res = subarraySum(arr, 5, 12);
    for (int i = 0; i < res.size(); i++)
        cout << res.at(i) << ", ";

    return 0;
}
