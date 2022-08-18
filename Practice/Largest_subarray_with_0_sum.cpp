// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// int maxLen(vector<int> &A, int n) // Brute Force
// {
//     int sum = 0;
//     int maxLen = -1;
//     for (int i = 0; i < n; i++) //Starting point of sub-array.
//     {
//         for (int j = i; j < n; j++) //Ending point of sub-array.
//         {
//             sum += A[j];
//             if (sum == 0)
//             {
//                 cout << "i= " << i << ", j= " << j << endl;
//                 maxLen = max(maxLen, (j - i + 1));
//             }
//         }
//         sum = 0; // For the next starting point sub-arrays
//     }

//     return maxLen;
// }

// int maxLen(vector<int> &A, int n) // Try
// // saving initial pointer in an array...
// {
//     int sum = 0;
//     int maxLen = -1;
//     vector<int> v1(n, -2);
//     vector<int> v2(n, 0);
//     int repeat = -1;
//     int count = 0;
//     int countRep = 0;
//     unordered_map<int, int> m;

//     // for(int i=0; i<n; i++)
//     // {
//     //     if(A[i]<0)
//     //         v[i] = -1;
//     //     else if(A[i]>=0)
//     //         v[i] = 1;
//     //     // else
//     //     //     v[i] = 0;
//     // }
//     for (int i = 0; i < n; i++)
//     {
//         sum = sum + A[i];
//         v1[i] = sum;
//     }
//     // for(int i=0; i<n; i++)
//     // {
//     //     cout<< v1[i]<<" "<<endl;
//     // }

//     v2 = v1;
//     sort(v2.begin(), v2.end()); // reqd for binary search

//     for (int i = 0; i < n; i++) // repeatition
//     {
//         // if (v2[i] == v2[i + 1])
//         // {
//         //     repeat = v2[i];
//         //     break;
//         // }
//         m[v1[i]] = m.at(v1[i]) + 1;
//     }
//     for (int i = 0; i < n; i++) // repeatition
//     {

//         cout << v1[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++) // repeatition
//     {
//         cout << m.at(v1[i]) << " ";
//     }

//     // for(int i=0; i<n; i++)
//     // {
//     //     if(m[A[i]] > 1)
//     //     {
//     //         v2.push_back(i);
//     //     }
//     // }

//     unordered_map<int, int>::iterator it = m.begin();
//     int first;
//     int i = 0;
//     cout<<endl;
//     while (it != m.end())
//     {
//         cout<<it->first<<" "<<it->second<<endl;
//         if (it->second > 1)
//         {
//             count++;
//             cout << count << endl;
//             if (count == 1)
//                 first = i;
//             else
//                 maxLen = max(maxLen, i);
//         }
//         i++;
//         it++;
//     }
//     // int first;
//     //     for(int i =0; i<n; i++)
//     //     {
//     //         if(m[v1[i]] > 1 )
//     //         {
//     //             count++;
//     //             cout<< count<<endl;
//     //                 if (count == 1)
//     //                     first = i;
//     //                 else
//     //                     maxLen = max(maxLen, i);
//     //         }
//     //     }

//     // if (repeat != -1)
//     // {
//     //     int first;
//     //     int i;
//     //     for (i = 0; i < n; i++)
//     //     {
//     //         if (v1[i] == repeat)
//     //         {
//     //             count++;
//     //             if (count == 1)
//     //                 first = i;
//     //             else
//     //                 maxLen = max(maxLen, i);
//     //         }
//     //     }
//     //     // cout<<first<<endl;
//     //     // cout<<count<<endl;
//     //     // cout<<count<<endl;

//     //     return (maxLen - first);
//     // }
//     // else
//     //     return 0;

//     return maxLen;
// }

int maxLen(vector<int> &A, int n) // Optimized: O(n)
{
    int sum = 0;
    unordered_map<int, int> m; // O(1) for insertion, deletion...etc. // Space complexity: O(n).

    int maxi = 0;

    for (int i = 0; i < n; i++) // O(n)
    {
        sum += A[i];

        if (sum == 0) // from 0th to ith index, the sum is zero. Therefore, it is a subarray with 0 sum.
        {
            maxi = i + 1;
        }
        else if (m.count(sum)) // if sum exists in the map m. // O(1)
        {
            maxi = max(maxi, i - m.at(sum));
        }
        else // the sum value occured 1st time.
        {
            m[sum] = i;
        }
    }

    return maxi;
}

int main()
{
    // vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    // vector<int> A = {18, 12, 15, -6, 3, -12, 21, 23};
    // vector<int> A = {18, 12, 15, -6, 3, -12, 100, -1, 1};
    // vector<int> A = {-1, 1, -1, 1}; // from 0th to ith index, the sum is zero. Therefore, it is a subarray with 0 sum.
    // vector<int> A = {63, 70, 80, 33, 33, 47, 20};
    vector<int> A = {1, 2, 3, 4, 0, 6};
    cout << "maxLen = " << maxLen(A, A.size());

    return 0;
}