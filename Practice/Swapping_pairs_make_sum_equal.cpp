// Swapping pairs make sum equal
// Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.
// Expected Time Complexity: O(MlogM+NlogN).
// Expected Auxiliary Space: O(1).

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// int findSwapValues(int A[], int n, int B[], int m)
// {
//     int sA = 0;
//     int sB = 0;
//     // bool flag = false;

//     for (int i = 0; i < n; i++)
//     {
//         sA += A[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         sB += B[i];
//     }

//     int sG = (sA + sB) / 2;

//     for (int i = 0; i < n; i++)
//     {
//         if (binary_search(B, B + m, sG - (sA - A[i])))
//             return 1;
//     }
//     for (int i = 0; i < m; i++)
//     {
//         if (binary_search(A, A + m, sG - (sB - B[i])))
//             return 1;
//     }

//     return -1;
// }

// int findSwapValues(int A[], int n, int B[], int m) // It works ✅ but got Time limit exceeded
// {
//     sort(A, A + n); // nlog(n)
//     sort(B, B + m); // nlog(n)

//     int sA = 0;
//     int sB = 0;
//     for (int i = 0; i < n; i++)
//         sA += A[i];
//     for (int i = 0; i < m; i++)
//         sB += B[i];

//     int end = (n < m) ? n : m;
//     // cout << "end = " << end << endl;

//     for (int i = 0; i < end; i++)
//     {
//         if (sA > sB)
//         {
//             if (A[i] < B[i])
//                 continue;
//             else
//             {
//                 int j = 0;
//                 while (sA - A[i] + B[j] != sB - B[j] + A[i] && A[i] > B[j] && j < m)
//                 {
//                     // cout << "A[i]"
//                     //      << " " << A[i] << " B[j]"
//                     //      << " " << B[j] << endl;
//                     if (sA - A[i] + B[j] == sB - B[j] + A[i])
//                         return 1;
//                     j++;
//                 }
//                 if (sA - A[i] + B[j] == sB - B[j] + A[i])
//                     return 1;
//             }
//         }
//         else
//         {
//             if (A[i] > B[i])
//                 continue;
//             else
//             {
//                 int j = i; //yes it was the code that worked but TLE
//                 while (sA - A[i] + B[j] != sB - B[j] + A[i] && A[i] < B[j] && j < m)
//                 {
//                     if (sA - A[i] + B[j] == sB - B[j] + A[i])
//                         return 1;
//                     j++;
//                 }
//                 if (sA - A[i] + B[j] == sB - B[j] + A[i])
//                     return 1;
//             }
//         }
//     }

//     return -1;
// }

int findSwapValues(int A[], int n, int B[], int m) // Optimized: O(mlogm+nlogn)
{
    // sort it so that we can use binary search
    sort(B, B + m); // nlog(n)
    int sA = 0;
    int sB = 0;
    // sum of elements in A
    for (int i = 0; i < n; i++)
        sA += A[i];
    // sum of elements in B and multiplying its each element by 2.
    for (int i = 0; i < m; i++)
    {
        sB += B[i];
        B[i] *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        if (binary_search(B, B + m, sB - sA + 2 * A[i]))
            return 1;
    }

    return -1;
}

int main()
{
    // // 👇🏻o/p: 1
    // int A[] = {4, 1, 2, 1, 1, 2};
    // int B[] = {3, 6, 3, 3};
    // // 👇🏻o/p: -1
    // int A[] = {5, 9, 16};
    // int B[] = {5, 8, 13};
    // 👇🏻o/p: 1
    int A[] = {5, 7, 4, 6};
    int B[] = {1, 2, 3, 8};
    cout << findSwapValues(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0]));

    return 0;
}