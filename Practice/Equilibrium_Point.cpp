// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array.
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
// Note: Retun the index of Equilibrium point. (1-based index)
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int equilibriumPoint(long long a[], int n) // Brute Force
// {

//     bool flag = false;
//     if (n == 1)
//         return 1;
//     else if (n == 2)
//         return -1;

//     int sumL = 0;
//     int sumR = 0;
//     int j;
//     for (int i = 0; i < n - 2; i++)
//     {
//         sumL += a[i];
//         cout << "sumL = " << sumL << endl;
//         j = n - 1;
//         while (j - i > 1)
//         {
//             sumR += a[j];
//             cout << "sumR = " << sumR << endl;
//             j--;
//         }
//         if (sumL == sumR)
//         {
//             flag = true;
//             break;
//         }
//         sumR = 0;
//         if (flag == true)
//             break;
//     }

//     if (flag == true)
//         return j = j + 1;
//     else
//         return -1;
// }

// int equilibriumPoint(long long a[], int n) // Try
// {
//     bool flag = false;
//     if (n == 1)
//         return 1;

//     // int sumL = 0;
//     // int sumR = 0;

//     // int i;
//     // for (i = 0; i < n; i++)
//     // {
//     //     sumL += a[i];
//     //     cout << "sumL=" << sumL << endl;

//     //     // if (n - 2 * i - 1 > 1)
//     //     {
//     //         if (sumL == sumR)
//     //         {
//     //             flag = true;
//     //             break;
//     //         }
//     //     }

//     //     sumR += a[n - i - 1];
//     //     cout << "sumR=" << sumR << endl;
//     // }
//     // if (flag)
//     //     return i = i + 1 + 1;
//     // else
//     //     return -1;

//     int sumJ = a[0];
//     int sumK = a[n - 1];

//     // for (int j = 1, k = n - 2; j < k; j++, k--)
//     // {
//     //     sumJ += a[j];
//     //     sumK += a[k];
//     // }
//     int outerWhile = 0;
//     int innerWhileJ = 0;
//     int innerWhileK = 0;
//     int j = 1, k = n - 2;
//     while (j != k)
//     {

//         outerWhile++;

//         if (sumJ < sumK)
//         {
//             innerWhileJ++;
//             sumJ += a[j];
//             j++;
//         }
//         if (sumJ > sumK)
//         {
//             innerWhileK++;
//             sumK += a[k];
//             k--;
//         }
//     }

//     cout << "outer while " << outerWhile << endl;
//     cout << "inner while j " << innerWhileJ << endl;
//     cout << "inner while k " << innerWhileK << endl;
//     if (sumJ == sumK && k - j == 0)
//     {
//         flag = true;
//     }

//     if (flag)
//         return j = j + 1;
//     else
//         return -1;
// }

int equilibriumPoint(long long a[], int n) // Optimized: O(n)
{
    bool flag = false;
    if (n == 1)
        return 1;
    int sumTotal = 0;
    int leftSum = 0;
    int rightSum = 0;

    for (int i = 0; i < n; i++)
        sumTotal += a[i];

    int i;
    for (i = 0; i < n - 1; i++)
    {
        leftSum = leftSum + a[i];
        rightSum = sumTotal - leftSum - a[i + 1];
        if (leftSum == rightSum)
        {
            flag = true;
            break;
        }
    }

    if (flag)
        return i = i + 1 + 1;
    else
        return -1;
}

int main()
{
    // long long int A[] = {1, 3, 5, 2, 2};
    // long long int A[] = {1, 3, 1, 4, 3, 2};
    long long int A[] = {10, 3, 1, 4, 3, 2};
    // long long int A[] = {1};
    cout << equilibriumPoint(A, sizeof(A) / sizeof(A[0]));

    return 0;
}