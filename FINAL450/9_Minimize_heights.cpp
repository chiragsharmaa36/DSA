// Minimize the Heights II
// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K.
// Decrease the height of the tower by K ( you can do this operation only if the height of the tower is greater than or equal to K)
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// Note: It is compulsory to increase or decrease the height by K for each tower.

// Expected Time Complexity: O(N*logN)
// Expected Auxiliary Space: O(N)

#include <iostream>
#include <climits>
#include <Algorithm>
#include <math.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// int getMinDiff(int arr[], int n, int k)
// {

//     int diff;
//     sort(arr, arr + n); // Nlog(N)
//     print(arr, n);
//     cout << endl;
//     diff = arr[n - 1] - arr[0];
//     int min = arr[0];
//     int max = arr[n - 1];
//     for (int i = 1; i < n; i++)
//     {
//         // if (arr[i] == k)
//         //     continue;

//         if (arr[i] >= k)
//         {
//             arr[i] = std::min(min, arr[i]-k);
//             // arr[i] = arr[i] - k;
//         }
//         else
//         {
//             arr[i] = std::max(max,arr[i]+k);
//             // arr[i] = arr[i] + k;
//         }
//         diff = std::min(diff, arr[i]-arr[i-1]);
//     }
//     print(arr, n);
//     cout << endl;

//     sort(arr, arr + n); // Nlog(N)
//     print(arr, n);
//     cout << endl;
//     // max = std::min(max, arr[n - 1]);
//     // min = std::max(min, arr[0]);
//     // int diff = std::min(arr[n-1]-arr[0], diffSimple);

//     return diff;
// }

// int getMinDiff(int arr[], int n, int k)
// {
//      for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= k)
//             arr[i] = arr[i] - k;
//         else
//             arr[i] = arr[i] + k;
//     }

// int count=0;
// for(int i=0; i<n; i++)
// {
//     if(arr[i]<=0)
//         count++;
// }

//    sort(arr, arr + n); // Nlog(N)
//    print(arr,n);

//     int diff = arr[n - 1] - arr[0];
//     return diff;
// }

// int getMinDiff(int arr[], int n, int k)
// {
//     int min = INT_MAX;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= k)
//         {
//             min = std::min(min, arr[i]);
//             if (arr[i] - k >= (2 * k - 1) && arr[i] + k >= (2 * k - 1))
//                 arr[i] = std::min(arr[i] + k, arr[i] - k);
//             else if (arr[i] - k >= (2 * k - 1))
//             {
//                 if (arr[i] + k >= k)
//                     arr[i] = arr[i] + k;
//                 else
//                     arr[i] = arr[i] - k;
//             }
//             else if (arr[i] + k >= (2 * k - 1))
//             {
//                 if (arr[i] - k >= k)
//                     arr[i] = arr[i] - k;
//                 else
//                     arr[i] = arr[i] + k;
//             }
//             // else
//             // {
//             //     arr[i] = std::min(arr[i] + k, arr[i] - k);
//             // }
//             arr[i] = std::min(min, arr[i]);
//         }
//         else
//         {
//             arr[i] = arr[i] + k;
//         }
//     }

//     cout << "Before sort" << endl;
//     print(arr, n);
//     sort(arr, arr + n); // Nlog(N)
//     cout << "After sort" << endl;
//     print(arr, n);
//     cout << endl;
//     int diff = arr[n - 1] - arr[0];

//     return diff;
// }

// int getMinDiff(int arr[], int n, int k) ...TRY
// {
//     sort(arr, arr + n); // Nlog(N)
//     print(arr, n);
//     cout << endl;
//     int Diff = arr[n - 1] - arr[0];

//     // Two-pointer method // Nlog(N)
//     int i = 0;
//     int j = n - 1;

// while (i <= j)
// {
//     if (arr[j] < k && arr[i] < k)
//     {
//         arr[i] = arr[i] + k;
//         arr[j] = arr[j] + k;
//         i++;
//         j--;
//     }
//     else if (arr[i] < k)
//     {
//         arr[i] = arr[i] + k;
//         i++;
//     }
//     else if (arr[j] == arr[i])
//     {
//         if (i != j)
//         {
//             arr[i] = arr[i] - k;
//             arr[j] = arr[j] - k;
//         }
//         else
//             arr[i] = arr[i] - k;

//         i++;
//         j--;
//     }
//     else if (arr[j] >= k && arr[i] >= k)
//     {
//         // if (arr[j] - arr[i] > abs(arr[j] - arr[i] - 2 * k))
//         {
//             arr[i] = arr[i] + k;
//             arr[j] = arr[j] - k;
//         }
//         // else
//         // {
//         //     arr[i] = arr[i] - k;
//         //     arr[j] = arr[j] - k;
//         // }
//         i++;
//         j--;
//     }
// }

//     while (i < j)
//     {
//         if(i==j)
//         {
//             arr[i] = arr[i] = k;
//         }
//         if (arr[j] >= k)
//         {
//             arr[j] = arr[j] - k;
//         }

//         arr[i] = arr[i] + k;
//             i++;
//             j--;

//     }

//     print(arr, n);
//     cout << endl;
//     sort(arr, arr + n); // Nlog(N)
//     return min(arr[n - 1] - arr[0], Diff);
//     return Diff;
// }

int getMinDiff(int arr[], int n, int k) // Optimized:O(n)✅
{

    sort(arr, arr + n);
    int minEle, maxEle;
    int result = arr[n - 1] - arr[0];

    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] >= k)
        {
            maxEle = max(arr[i - 1] + k, arr[n - 1] - k);
            minEle = min(arr[0] + k, arr[i] - k);

            result = min(result, maxEle - minEle);
        }
    }

    return result;
}

int main()
{
    // int arr[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1}; int k=5; /*output:7*/
    // int arr[] = {5, 5, 8, 6, 4, 10, 3, 8, 9, 10}; int k=5; /*output:7*/
    // int arr[] = {1, 5, 8, 10}; int k=2; /*output:5*/
    int arr[] = {3, 9, 12, 16, 20};
    int k = 3; /*output:11*/
    cout << getMinDiff(arr, sizeof(arr) / sizeof(arr[0]), k);
}