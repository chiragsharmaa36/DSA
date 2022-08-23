// Swapping pairs make sum equal
// Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.
// Expected Time Complexity: O(MlogM+NlogN).
// Expected Auxiliary Space: O(1).

#include <iostream>
#include <algorithm>
using namespace std;

int findSwapValues(int A[], int n, int B[], int m)
{
    int sA = 0;
    int sB = 0;
    // bool flag = false;

    for (int i = 0; i < n; i++)
    {
        sA += A[i];
    }
    for (int i = 0; i < m; i++)
    {
        sB += B[i];
    }

    int sG = (sA + sB) / 2;

    for (int i = 0; i < n; i++)
    {
        if (binary_search(B, B + m, sG - (sA - A[i])))
            return 1;
    }
    for (int i = 0; i < m; i++)
    {
        if (binary_search(A, A + m, sG - (sB - B[i])))
            return 1;
    }


        return -1;
}

int main()
{
    // 👇🏻o/p: 1
    // int B[] = {4, 1, 2, 1, 1, 2};
    // int A[] = {3, 6, 3, 3};
    // 👇🏻o/p: -1
    int A[] = {5, 9, 16};
    int B[] = {5, 8, 13};
    cout << findSwapValues(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0]));

    return 0;
}