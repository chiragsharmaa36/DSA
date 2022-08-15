// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int maxLen(vector<int> &A, int n) // Brute Force
// {
//     int sum = 0;
//     int maxLen = -1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             sum += A[j];
//             if (sum == 0)
//             {
//                 cout << "i= " << i << ", j= " << j << endl;
//                 maxLen = max(maxLen, (j - i + 1));
//             }
//         }
//         sum = 0;
//     }

//     return maxLen;
// }

int maxLen(vector<int> &A, int n) // Try
// saving initial pointer in an array...
{
    int sum = 0;
    int maxLen = -1;
    vector<int> v1(n, -2);
    vector<int> v2(n, 0);
    int repeat = -1;
    int count = 0;
    int countRep = 0;

    // for(int i=0; i<n; i++)
    // {
    //     if(A[i]<0)
    //         v[i] = -1;
    //     else if(A[i]>=0)
    //         v[i] = 1;
    //     // else
    //     //     v[i] = 0;
    // }
    for (int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        v1[i] = sum;
    }
    // for(int i=0; i<n; i++)
    // {
    //     cout<< v1[i]<<" "<<endl;
    // }

    v2 = v1;
    sort(v2.begin(), v2.end()); // reqd for binary search

    for (int i = 0; i < n - 1; i++) // repeatition
    {
        if (v2[i] == v2[i + 1])
        {
            // countRep++;
            repeat = v2[i];
            break;
        }
    }

    if (repeat != -1)
    {
        int first;
        int i;
        for (i = 0; i < n; i++)
        {
            if (v1[i] == repeat)
            {
                count++;
                if (count == 1)
                    first = i;
                else
                    maxLen = max(maxLen, i);
            }
        }
        // cout<<first<<endl;
        // cout<<count<<endl;
        // cout<<count<<endl;

        return (maxLen - first);
    }
    else
        return 0;
}

int main()
{
    // vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    // vector<int> A = {18, 12, 15, -6, 3, -12, 21, 23};
    vector<int> A = {18, 12, 15, -6, 3, -12, 100, -1, 1};
    // int a[] = {63, 70, 80, 33, 33, 47, 20};
    // int a[] = {1,2,3,4,0};
    cout << "maxLen = " << maxLen(A, A.size());

    return 0;
}